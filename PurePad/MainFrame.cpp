#include "MainFrame.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

MainFrame::MainFrame(const wxString& title, const wxSize& size,	long style)
	:
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style)
{
	wxInitAllImageHandlers();
	wxString pathToIcons = wxGetCwd() + "\\Icons\\";

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* genSizer;
	genSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* noteSizer;
	noteSizer = new wxBoxSizer(wxVERTICAL);

	genNotebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	noteSizer->Add(genNotebook, 1, wxEXPAND | wxALL, 0);


	genSizer->Add(noteSizer, 1, wxEXPAND, 0);

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* buttonsSizer;
	buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

	addBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	addBtn->SetBitmap(wxBitmap(pathToIcons + "addBtn.png", wxBITMAP_TYPE_ANY));
	addBtn->SetBitmapPressed(wxBitmap(pathToIcons + "addBtnPressed.png", wxBITMAP_TYPE_ANY));
	addBtn->SetToolTip(wxT("Add page"));
	addBtn->SetBackgroundColour(Colors::darkGray);

	buttonsSizer->Add(addBtn, 0, wxLEFT, this->FromDIP(5));

	codeBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	codeBtn->SetBitmap(wxBitmap(pathToIcons + "codeBtn.png", wxBITMAP_TYPE_ANY));
	codeBtn->SetBitmapPressed(wxBitmap(pathToIcons + "codeBtnPressed.png", wxBITMAP_TYPE_ANY));
	codeBtn->SetToolTip(wxT("Add code page"));
	codeBtn->SetBackgroundColour(Colors::darkGray);

	buttonsSizer->Add(codeBtn, 0, wxLEFT, this->FromDIP(5));


	delBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	delBtn->SetBitmap(wxBitmap(pathToIcons + "delBtn.png", wxBITMAP_TYPE_ANY));
	delBtn->SetBitmapPressed(wxBitmap(pathToIcons + "delBtnPressed.png", wxBITMAP_TYPE_ANY));
	delBtn->SetToolTip(wxT("Delete page"));
	delBtn->SetBackgroundColour(Colors::darkGray);

	buttonsSizer->Add(delBtn, 0, wxLEFT, this->FromDIP(5));


	editNameBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	editNameBtn->SetBitmap(wxBitmap(pathToIcons + "editBtn.png", wxBITMAP_TYPE_ANY));
	editNameBtn->SetBitmapPressed(wxBitmap(pathToIcons + "editBtnPressed.png", wxBITMAP_TYPE_ANY));
	editNameBtn->SetToolTip(wxT("Edit page name"));
	editNameBtn->SetBackgroundColour(Colors::darkGray);

	buttonsSizer->Add(editNameBtn, 0, wxLEFT, this->FromDIP(5));

	
	tabFillerLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	tabFillerLabel->Wrap(-1);
	buttonsSizer->Add(tabFillerLabel, 12, 0, 5);


	optionsBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	optionsBtn->SetBitmap(wxBitmap(pathToIcons + "arrowBtn.png", wxBITMAP_TYPE_ANY));
	optionsBtn->SetBitmapPressed(wxBitmap(pathToIcons + "arrowBtnPressed.png", wxBITMAP_TYPE_ANY));
	optionsBtn->SetToolTip(wxT("More options"));
	optionsBtn->SetBackgroundColour(Colors::darkGray);

	buttonsSizer->Add(optionsBtn, 0, wxRIGHT, this->FromDIP(5));


	menuSizer->Add(buttonsSizer, 1, wxLEFT, 0);

	wxBoxSizer* tabSizer;
	tabSizer = new wxBoxSizer(wxVERTICAL);

	menuSizer->Add(tabSizer, 1, wxEXPAND, 0);

	genSizer->Add(menuSizer, 0, wxEXPAND, 0);

	this->SetClientSize(this->FromDIP(300), this->FromDIP(500));
	this->SetBackgroundColour(Colors::darkGray);
	this->SetSizer(genSizer);
	this->Layout();
	this->Centre(wxBOTH);

	BindEvents();
	LoadPagesFromTextFiles();
}

MainFrame::~MainFrame()
{
}

void MainFrame::BindEvents()
{
	addBtn->Bind(wxEVT_BUTTON, &MainFrame::AddPage, this);
	codeBtn->Bind(wxEVT_BUTTON, &MainFrame::AddCodePage, this);
	delBtn->Bind(wxEVT_BUTTON, &MainFrame::DeletePage, this);
	editNameBtn->Bind(wxEVT_BUTTON, &MainFrame::RenamePage, this);
	optionsBtn->Bind(wxEVT_BUTTON, &MainFrame::UpdateCodeOptions, this);
	genNotebook->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, &MainFrame::UpdateCurrentCodeLang, this);

	//this->Bind(wxEVT_SET_FOCUS, &MainFrame::CloseOptionsOnFocus, this);
	Bind(wxEVT_CLOSE_WINDOW, &MainFrame::SavePagesToTextFiles, this);
}

void MainFrame::AddPage(wxCommandEvent& event)
{
	int pageNum = genNotebook->GetPageCount();
	std::string page = "new" + std::to_string(pageNum + 1);
	wxString pageName(page);
	CreatePage(pageName);
}

void MainFrame::CreatePage(wxString& inPageName)
{
	wxPanel* newPage = new wxPanel(genNotebook);
	wxBoxSizer* pageTextSizer = new wxBoxSizer(wxVERTICAL);
	wxTextCtrl* pageTextCtrl = new wxTextCtrl(newPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	wxFont font = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New"));
	pageTextCtrl->SetFont(font);
	pageTextSizer->Add(pageTextCtrl, 1, wxEXPAND, 5);
	newPage->SetSizer(pageTextSizer);
	newPage->Layout();

	genNotebook->AddPage(newPage, inPageName, true);
}

void MainFrame::AddCodePage(wxCommandEvent& event)
{
	int pageNum = genNotebook->GetPageCount();
	std::string page = "new" + std::to_string(pageNum + 1) + ".cpp";
	wxString pageName(page);
	CreateCodePage(pageName);
}

void MainFrame::CreateCodePage(wxString& inPageName)
{
	wxPanel* newCodePage = new wxPanel(genNotebook);
	wxBoxSizer* codePageTextSizer = new wxBoxSizer(wxVERTICAL);

	wxStyledTextCtrl* codeStyledText = new wxStyledTextCtrl(newCodePage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxEmptyString);

	{
		wxFont font = wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New"));
		codeStyledText->StyleSetFont(wxSTC_STYLE_DEFAULT, font);
	}

	codeStyledText->StyleClearAll();
	codeStyledText->SetLexer(wxSTC_LEX_CPP);

	codeStyledText->SetMarginWidth(0, codeStyledText->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	codeStyledText->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
	codeStyledText->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
	codeStyledText->SetMarginType(0, wxSTC_MARGIN_NUMBER);


	codeStyledText->SetMarginType(wxSTC_MARGIN_NUMBER, wxSTC_MARGIN_SYMBOL);
	codeStyledText->SetMarginWidth(wxSTC_MARGIN_NUMBER, 15);
	codeStyledText->SetMarginMask(wxSTC_MARGIN_NUMBER, wxSTC_MASK_FOLDERS);
	codeStyledText->StyleSetBackground(wxSTC_MARGIN_NUMBER, wxColor(200, 200, 200));
	codeStyledText->SetMarginSensitive(wxSTC_MARGIN_NUMBER, true);

	codeStyledText->SetProperty(wxT("fold"), wxT("1"));
	codeStyledText->SetProperty(wxT("fold.comment"), wxT("1"));
	codeStyledText->SetProperty(wxT("fold.compact"), wxT("1"));

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, Colors::lightGray);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_ARROWDOWN);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, Colors::lightGray);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERSUB, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERSUB, Colors::lightGray);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_ARROW);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERMIDTAIL, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERMIDTAIL, Colors::lightGray);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERTAIL, Colors::lightGray);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERTAIL, Colors::lightGray);


	//codeStyledText->SetWrapMode(wxSTC_WRAP_WORD); 
	codeStyledText->SetWrapMode(wxSTC_WRAP_NONE);


	codeStyledText->StyleSetForeground(wxSTC_C_STRING, Colors::string);
	codeStyledText->StyleSetForeground(wxSTC_C_PREPROCESSOR, Colors::preprocessor);
	codeStyledText->StyleSetForeground(wxSTC_C_IDENTIFIER, Colors::identifier);
	codeStyledText->StyleSetForeground(wxSTC_C_NUMBER, Colors::number);
	codeStyledText->StyleSetForeground(wxSTC_C_CHARACTER, Colors::character);
	codeStyledText->StyleSetForeground(wxSTC_C_WORD, Colors::word);
	codeStyledText->StyleSetForeground(wxSTC_C_WORD2, Colors::word2);
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENT, Colors::comment);
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTLINE, Colors::commentLine);
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOC, Colors::commentDoc);
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD, Colors::commentDocKeyword);
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, Colors::commentDocKeywordError);
	codeStyledText->StyleSetBold(wxSTC_C_WORD, true);
	codeStyledText->StyleSetBold(wxSTC_C_WORD2, true);
	codeStyledText->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

	codeStyledText->SetKeyWords(0, Keywords::cpp);
	codeStyledText->SetKeyWords(1, Keywords::cpp2);

	codePageTextSizer->Add(codeStyledText, 1, wxEXPAND, 5);

	newCodePage->SetSizer(codePageTextSizer);
	newCodePage->Layout();

	genNotebook->AddPage(newCodePage, inPageName, true);

	Settings::codePageLang.insert({ genNotebook->GetSelection(), CodeLang::CPP });
}

void MainFrame::DeletePage(wxCommandEvent& event)
{
	if (genNotebook->GetSelection() == wxNOT_FOUND)
	{
		return;
	}

	deletePageDialog = new DeletePageDialog(this);
	
	if (deletePageDialog->ShowModal() == wxID_OK)
	{
		std::filesystem::path pathToCwd = std::filesystem::current_path();
		std::filesystem::path pathToPages = pathToCwd / "Pages";
		std::filesystem::path pathToDelFile;

		for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(pathToPages))
		{
			std::filesystem::path pathToFile = dirEntry.path();
			std::string fileName = pathToFile.filename().string();
			fileName = fileName.substr(0, fileName.length() - 4);

			if (fileName == genNotebook->GetPageText(genNotebook->GetSelection()).ToStdString() ||
				fileName == genNotebook->GetPageText(genNotebook->GetSelection()).ToStdString() + "_codePage")
			{
				pathToDelFile = pathToFile;
			}
		}
		
		if (!pathToDelFile.empty())
		{
			std::filesystem::remove(pathToDelFile);
		}
		genNotebook->DeletePage(genNotebook->GetSelection());
	}
	else
	{
		return;
	}
	
}

void MainFrame::RenamePage(wxCommandEvent& event)
{
	if (genNotebook->GetSelection() == wxNOT_FOUND)
	{
		return;
	}

	renamePageDialog = new RenamePageDialog(this);

	if (renamePageDialog->ShowModal() == wxID_OK)
	{
		if (renamePageDialog->GetNameText() != wxString(""))
		{
			genNotebook->SetPageText(genNotebook->GetSelection(), renamePageDialog->GetNameText());
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}

void MainFrame::ToggleWordWrap(wxCommandEvent& event)
{
}

void MainFrame::UpdateCodeOptions(wxCommandEvent& event)
{
	if (genNotebook->GetSelection() == wxNOT_FOUND)
	{
		return;
	}

	if (codeOptionsDialog)
	{
		codeOptionsDialog = nullptr;
	}

	wxWindow* pagePanel = genNotebook->GetPage(genNotebook->GetSelection());
	wxWindowList pageChildren = pagePanel->GetChildren();
	wxStyledTextCtrl* pageTextCtrl = dynamic_cast<wxStyledTextCtrl*>(pageChildren[0]);
	if (pageTextCtrl) 
	{
		codeOptionsDialog = new CodeOptionsDialog(genNotebook);
		codeOptionsDialog->Show(true);
		//optionsBtn->Disable();
	}
}

void MainFrame::UpdateCurrentCodeLang(wxBookCtrlEvent& event)
{
	if (Settings::codePageLang.find(genNotebook->GetSelection()) != Settings::codePageLang.end())
	{
		Keywords::currentCodeLang = Settings::codePageLang.at(genNotebook->GetSelection());

		UpdateSyntaxHighlight(Keywords::currentCodeLang);
	}
}

void MainFrame::UpdateSyntaxHighlight(CodeLang inLang)
{
	wxWindow* curPage = genNotebook->GetCurrentPage();
	wxWindowList pageChildren = curPage->GetChildren();
	wxStyledTextCtrl* pageTextCtrl = dynamic_cast<wxStyledTextCtrl*>(pageChildren[0]);

	if (pageTextCtrl)
	{
		pageTextCtrl->SetKeyWords(0, "");
		pageTextCtrl->SetKeyWords(1, "");

		switch (inLang)
		{
		case CPP:
			//pageTextCtrl->ClearDocumentStyle();
			pageTextCtrl->SetKeyWords(0, Keywords::cpp);
			pageTextCtrl->SetKeyWords(1, Keywords::cpp2);
			break;

		case PYTHON:
			//pageTextCtrl->ClearDocumentStyle();
			pageTextCtrl->SetKeyWords(0, Keywords::python);
			pageTextCtrl->SetKeyWords(1, Keywords::python);
			break;

		case JAVA:
			//pageTextCtrl->ClearDocumentStyle();
			pageTextCtrl->SetKeyWords(0, Keywords::java);
			pageTextCtrl->SetKeyWords(1, Keywords::java2);
			break;

		case JS:
			//pageTextCtrl->ClearDocumentStyle();
			pageTextCtrl->SetKeyWords(0, Keywords::javaScript);
			pageTextCtrl->SetKeyWords(1, Keywords::javaScript2);
			break;

		default:
			break;
		}
	}
}

void MainFrame::SavePagesToTextFiles(wxCloseEvent& event)
{
	
	size_t pageCount = genNotebook->GetPageCount();

	if (pageCount == 0)
	{
		Destroy();
		return;
	}

	std::filesystem::path pathToCwd = std::filesystem::current_path();
	std::filesystem::path pathToPages = pathToCwd / "Pages";
	std::filesystem::remove_all(pathToPages);
	std::filesystem::create_directory(pathToPages);
	
	for (size_t i = 0; i < pageCount; i++)
	{
		wxWindow* pagePanel = genNotebook->GetPage(i);
		wxWindowList pageChildren = pagePanel->GetChildren();
		wxTextCtrl* pageTextCtrl = dynamic_cast<wxTextCtrl*>(pageChildren[0]);

		if (pageTextCtrl) 
		{
			std::string textValue = pageTextCtrl->GetValue().ToStdString();
			std::string pageName = genNotebook->GetPageText(i).ToStdString();
			pageName += ".txt";
			std::string pathToFile = pathToPages.string() + "\\" + pageName;
			std::ofstream pageFile(pathToFile);

			pageFile << textValue;

			pageFile.close();
		}
		else
		{
			wxStyledTextCtrl* codePageTextCtrl = dynamic_cast<wxStyledTextCtrl*>(pageChildren[0]);
			if (codePageTextCtrl)
			{ 
				std::string textValue = codePageTextCtrl->GetValue().ToStdString();
				std::string pageName = genNotebook->GetPageText(i).ToStdString();
				std::string pathToFile = pathToPages.string() + "\\" + pageName;
				std::ofstream pageFile(pathToFile);
				
				pageFile << textValue;

				pageFile.close();
			}
			else
			{
				continue;
			}
		}
	}
	
	Destroy();
}

void MainFrame::LoadPagesFromTextFiles()
{
	
	std::filesystem::path pathToCwd = std::filesystem::current_path();
	std::filesystem::path pathToPages = pathToCwd / "Pages";

	if (std::filesystem::is_empty(pathToPages))
	{
		return;
	}

	int pageIndex = -1;
	for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(pathToPages))
	{
		if (dirEntry.exists())
		{
			if (dirEntry.file_size() != 0)
			{
				pageIndex++;

				std::filesystem::path pathToFile = dirEntry.path();
				std::filesystem::path fileNamePath = pathToFile.filename();
				std::filesystem::path extensionPath = pathToFile.extension();
				std::string extension = extensionPath.string();

				std::string pageName = fileNamePath.string();
				

				std::ifstream fileText(pathToFile);
				std::string textFromFile;
				std::string textForPage;
				while (std::getline(fileText, textFromFile))
				{
					textForPage += textFromFile;
					textForPage += '\n';
				}
				wxString wxTextForPage(textForPage);

				
				// create code page
				if (extension != ".txt")
				{
					if (extension == ".cpp") Settings::codePageLang.insert({ pageIndex, CodeLang::CPP});
					else if (extension == ".py") Settings::codePageLang.insert({ pageIndex, CodeLang::PYTHON });
					else if (extension == ".java") Settings::codePageLang.insert({ pageIndex, CodeLang::JAVA });
					else if (extension == ".js") Settings::codePageLang.insert({ pageIndex, CodeLang::JS });

					//pageName = pageName.substr(0, pageName.length() - 4);
					wxString wxPageName(pageName);
					CreateCodePage(wxPageName);
					
					wxWindow* pagePanel = genNotebook->GetPage(genNotebook->GetPageCount() - 1);
					wxWindowList pageChildren = pagePanel->GetChildren();
					wxStyledTextCtrl* pageTextCtrl = dynamic_cast<wxStyledTextCtrl*>(pageChildren[0]);
					pageTextCtrl->SetValue(wxTextForPage);
				}
				else
				{
					pageName = pageName.substr(0, pageName.length() - 4);	// remove file extension
					wxString wxPageName(pageName);
					CreatePage(wxPageName);

					wxWindow* pagePanel = genNotebook->GetPage(genNotebook->GetPageCount() - 1);
					wxWindowList pageChildren = pagePanel->GetChildren();
					wxTextCtrl* pageTextCtrl = dynamic_cast<wxTextCtrl*>(pageChildren[0]);
					pageTextCtrl->SetValue(wxTextForPage);
				}
			}
		}
	}
	
}
