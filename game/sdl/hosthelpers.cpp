#include <sys/stat.h>
#include "game/sdl/hosthelpers.h"
#include "game/sdl/sdlhttpservice.h"


namespace wi {

char gszMainDataDir[PATH_MAX];          // data file (htdata832.pdb, htsfx.pdb) dir
char gszTempDir[PATH_MAX];              // temp file directory
char gszMissionPacksDir[PATH_MAX];      // downloaded mission packs
char gszMissionPackInfosDir[PATH_MAX];
char gszSaveGamesDir[PATH_MAX];         // saved games
char gszPrefsFilename[PATH_MAX];        // game prefs
char gszCompletesDir[PATH_MAX];         // for "mission completed" tracking
HttpService *gphttp;

bool HostHelpers::Init() {
	char pszHomeDir[PATH_MAX];
    //sprintf(gszMainDataDir, "%s/..", pszAppDir);	//should use readlink("/proc/self/exe", buf, bufsize);
	#ifdef PANDORA
    sprintf(gszMainDataDir, ".");
	#else
    sprintf(gszMainDataDir, "..");
	#endif

    // This returns the user's home directory; Library, and Documents are in it
    sprintf(pszHomeDir,"%s/.hostile-takeover", getenv("HOME"));

    strcpy(gszTempDir, "/tmp");
    sprintf(gszMissionPacksDir, "%s/MissionPacks", pszHomeDir);
    sprintf(gszMissionPackInfosDir, "%s/MissionPackInfos", pszHomeDir);
    sprintf(gszSaveGamesDir, "%s/SaveGames", pszHomeDir);
    sprintf(gszCompletesDir, "%s/Completes", pszHomeDir);
    sprintf(gszPrefsFilename, "%s/prefs.bin", pszHomeDir);

    // Make the directories under Library
    mkdir(pszHomeDir, 0755);
    mkdir(gszMissionPacksDir, 0755);
    mkdir(gszMissionPackInfosDir, 0755);
    mkdir(gszSaveGamesDir, 0755);
    mkdir(gszCompletesDir, 0755);

    // SDL specific http service
    extern HttpService *gphttp;
    gphttp = (HttpService *)new SdlHttpService;

    return true;
}

void HostHelpers::Cleanup() {
    delete gphttp;
}

const char *HostHelpers::GetMainDataDir() {
    return gszMainDataDir;
}

const char *HostHelpers::GetTempDir() {
	return gszTempDir;
}

const char *HostHelpers::GetMissionPacksDir() {
	return gszMissionPacksDir;
}

const char *HostHelpers::GetMissionPackInfosDir() {
	return gszMissionPackInfosDir;
}

const char *HostHelpers::GetSaveGamesDir() {
	return gszSaveGamesDir;
}

const char *HostHelpers::GetCompletesDir() {
	return gszCompletesDir;
}

const char *HostHelpers::GetPrefsFilename() {
	return gszPrefsFilename;
}

void HostHelpers::OpenUrl(const char *pszUrl) {
    Log("HostHelpers::OpenUrl not implemented yet");
}
    
void HostHelpers::Log(const char *pszFormat, va_list va)
{
#if 0
    LOGX() << base::Log::vFormat(pszFormat, va);
#endif

    char sz[512];
    vsnprintf(sz, sizeof(sz), pszFormat, va);

    printf("%s\n", sz);
}

void HostHelpers::Log(const char *pszFormat, ...)
{
    va_list va;
    va_start(va, pszFormat);
    Log(pszFormat, va);
    va_end(va);
}

void HostHelpers::MessageBox(const char *pszFormat, va_list va)
{
    Log(pszFormat, va);
}

void HostHelpers::Break()
{
    Log("BREAK!!");
}

void HostHelpers::GetSurfaceProperties(SurfaceProperties *pprops)
{
#if 0
    [g_appDelegate getSurfaceProperties: pprops];
#else
    Log("HostHelpers::GetSurfaceProperties not implemented yet");
#endif
}

void HostHelpers::FrameStart()
{
#if 0
    [g_appDelegate frameStart];
#else
    Log("HostHelpers::FrameStart not implemented yet");
#endif
}

void HostHelpers::FrameComplete(int cfrmm, UpdateMap **apupd, Rect *arc,
        bool fScrolled)
{
#if 0
    [g_appDelegate frameComplete:cfrmm maps:apupd rects:arc scrolled:fScrolled];
#else
    Log("HostHelpers::FrameComplete not implemented yet");
#endif
}

void HostHelpers::ResetScrollOffset()
{
#if 0
    [g_appDelegate resetScrollOffset];
#else
    Log("HostHelpers::ResetScrollOffset not implemented yet");
#endif
}

void HostHelpers::SetFormMgrs(FormMgr *pfrmmSim, FormMgr *pfrmmInput)
{
#if 0
    return [g_appDelegate setFormMgrs:pfrmmSim input:pfrmmInput];
#else
    Log("HostHelpers::SetFormMgrs not implemented yet");
#endif
}

DibBitmap *HostHelpers::CreateFrontDib(int cx, int cy, int nDegreeOrientation)
{
#if 0
    return [g_appDelegate createFrontDibWithOrientation:nDegreeOrientation width:cx height:cy];
#else
    Log("HostHelpers::CreateFrontDib not implemented yet");
    return NULL;
#endif
}
    
void HostHelpers::SetPalette(Palette *ppal)
{
#if 0
    [g_appDelegate setPalette:ppal];
#else
    Log("HostHelpers::SetPalette not implemented yet");
#endif
}

static char gszUdid[20];

const char *HostHelpers::GetUdid()
{
#if 0
    return [g_appDelegate getUdid];
#else
	// TODO(darrinm): talk to Scott about Udid requirements
	char *pch = gszUdid;
	if (*pch == 0) {
		for (int i = 0; i < 19; i++)
			*pch++ = '0' + GetAsyncRandom() % 10;
		*pch = 0;
	}
    return gszUdid;
#endif
}

bool HostHelpers::IsExiting()
{
#if 0
    return [g_appDelegate isExiting];
#else
    Log("HostHelpers::IsExitig not implemented yet");
    return false;
#endif
}

void HostHelpers::InitiateAsk(const char *title, int max, const char *def,
        int keyboard, bool secure)
{
#if 0
    BOOL s = secure ? YES : NO;
    return [g_appDelegate initiateAsk:title max:max default:def
            keyboard:keyboard secure:s];
#else
    Log("HostHelpers::InitiateAsk not implemented yet");
#endif
}

void HostHelpers::GetAskString(char *psz, int cb)
{
#if 0
    return [g_appDelegate getAskString:psz size:cb];
#else
    Log("HostHelpers::GetAskString not implemented yet");
#endif
}

IChatController *HostHelpers::GetChatController()
{
#if 0
    return [g_appDelegate getChatController];
#else
    Log("HostHelpers::GetChatController not implemented yet");
    return NULL;
#endif
}

void HostHelpers::InitiateWebView(const char *title, const char *url) {
#if 0
    [g_appDelegate initiateWebView:title withUrl:url];
#else
    Log("HostHelpers::InitiateWebView not implemented yet");
#endif
}

void HostHelpers::GameThreadStart(void *pv) {
    Log("Starting game...");
    wi::GameMain((char *)""); 
}

int HostHelpers::main(int argc, char **argv)
{
    // TODO(darrinm): should SDL call this?
#if 0
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    return UIApplicationMain(argc, argv, nil, @"IPhoneAppDelegate");
#else
    Log("HostHelpers::main not implemented yet");
#endif
    return 0;
}

};	//namespace wi