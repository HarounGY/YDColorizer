#include "Path.h"
#include "Tool.h"
#include <direct.h>
/*************************************************
Function:         |GetPath
Description:      |��ȡDLL����Ŀ¼
Calls:            |GetDLLPath
Return:           |DLL����Ŀ¼����\��β��·��
Others:           |����޸���ɫ�����Ŀ¼����Ҫ�޸�DLLpath������·��������
*************************************************/
char* Path::GetPath()
{
	char* buffer = GetDLLPath();
	Tool().CharAddChar(buffer, MAX_PATH, DLLpath, strlen(DLLpath));
	//for (int i = 0; i < MAX_PATH; i++) {
	//	if (buffer[i] == '\0') {
	//		for (int j = 0; i < MAX_PATH - 1 && j < strlen(DLLpath); i++, j++) {
	//			buffer[i] = DLLpath[j];
	//		}
	//		buffer[i] = '\0';//��ֹ·��������
	//		break;
	//	}
	//}
	/*size_t size = sizeof(WCHAR)*MAX_PATH;
	WCHAR* path = (WCHAR*)malloc(size);
	memset(path, 0, size);
	MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer) + 1, path,
		size / sizeof(WCHAR));
	free(buffer);*/
	return buffer;
}
/*************************************************
Function:         |GetDLLPath
Description:      |��ȡ����Ŀ¼
Return:           |YDWE��Ŀ¼������\��β��·��
*************************************************/
char * Path::GetDLLPath()
{
	char*buffer = (char*)malloc(MAX_PATH);
	_getcwd(buffer, MAX_PATH);
	return buffer;
}