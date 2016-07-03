#include "thread.h"
#include <tesseract/baseapi.h>
#include <tesseract/ocrclass.h>
#include <leptonica/allheaders.h>
#include <QPixmap>

bool progress(int progress, int left, int right, int top, int bottom)
{
    qDebug("%d %d %d %d %d", progress, left, right, top, bottom);
    return false;
}

void runThread(const QString &imageFile)
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead(imageFile.toStdString().c_str());
    api->SetImage(image);

    ETEXT_DESC monitor;
    monitor.progress_callback = progress;
    api->Recognize(&monitor);

    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);
}
