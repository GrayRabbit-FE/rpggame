#include<windows.h>
DWORD WINAPI bgm(LPVOID lpParam)
{
	PlaySoundW(L"resource\\bgm.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0L;
}
void playbgm()
{
	HANDLE hThread =  CreateThread(NULL, 0,bgm, NULL, 0, NULL);
}