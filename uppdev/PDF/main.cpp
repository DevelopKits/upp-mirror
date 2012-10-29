#include <PdfDraw/PdfDraw.h>

using namespace Upp;

#define IMAGECLASS AppImg
#define IMAGEFILE <PDF/app.iml>
#include <Draw/iml.h>

CONSOLE_APP_MAIN
{
	PdfDraw pdf;
	pdf.DrawRect(400, 400, 500, 500, Blue);
	pdf.DrawText(100, 100, "Ahoj", Roman(100), Black);
	pdf.DrawText(100, 200, "Ahoj", Arial(100), Black);
	pdf.DrawImage(100, 500, 200, 200, AppImg::test());
	pdf.DrawImage(300, 500, 200, 200, AppImg::testbw());
	pdf.DrawImage(500, 500, 200, 200, AppImg::testg());
	SaveFile(GetHomeDirFile("pdf.pdf"), pdf.Finish());
}
