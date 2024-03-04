#include <iostream>
#include "Menu.h"
#include <Windows.h>
#include <string>
#include <ShObjIdl.h>

using namespace std;

void Menu::startScreen() {
	chooseFile();
}
string Menu::textName() {
	return filePath;
}
bool Menu::chooseFile() {
	// Creating a instance for COM to interact with code
	HRESULT file = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (FAILED(file))
		return FALSE;
	// creating a fileopendialog object
	IFileOpenDialog* FileSystem;
	file = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&FileSystem));
	if (FAILED(file)) {
		CoUninitialize();
		return FALSE;
	}
	// showing the file explorer
	file = FileSystem->Show(NULL);
	if (FAILED(file)) {
		FileSystem->Release();
		CoUninitialize();
		return FALSE;
	}
	// grab file name
	IShellItem* files;
	file = FileSystem->GetResult(&files);
	if (FAILED(file)) {
		FileSystem->Release();
		CoUninitialize();
		return FALSE;
	}
	// store path
	PWSTR Path;
	file = files->GetDisplayName(SIGDN_FILESYSPATH, &Path);
	if (FAILED(file)) {
		files->Release();
		FileSystem->Release();
		CoUninitialize();
		return FALSE;
	}
	// change name to redeable and store path
	wstring path(Path);
	string c(path.begin(), path.end());
	filePath = c;

	// getting rid of slashs for name
	const size_t slash = filePath.find_last_of("/\\");
	selectedFile = filePath.substr(slash + 1);

	// releasing and stopping CoInitialize
	CoTaskMemFree(Path);
	files->Release();
	FileSystem->Release();
	CoUninitialize();
	return TRUE;
}
