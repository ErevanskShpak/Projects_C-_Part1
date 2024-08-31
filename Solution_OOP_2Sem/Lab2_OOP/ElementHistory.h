#pragma once
#include <iostream>
#include <string>

using namespace std;

class ElementHistory {
	string editor;
	string name;
	string formatStart;
	string formatEnd;
	bool success;

	bool isEditorCorrect();
public:
	ElementHistory() : success(true) {}
	ElementHistory(string editor, string name, string formatStart, string formatEnd, bool success) :editor(editor), name(name),
		formatStart(formatStart), formatEnd(formatEnd), success(success) {}

	void setEditor();
	void setEditor(string editor) { this->editor = editor; }
	void setName(string name) { this->name = name; }
	void setFormatStart(string formatStart) { this->formatStart = formatStart; }
	void setFormatEnd(string formatEnd) { this->formatEnd = formatEnd; }
	void setSuccess(bool success) { this->success = success; }
	string getEditor() const { return editor; }
	string getName() const { return name; }
	string getFormatStart() const { return formatStart; }
	string getFormatEnd() const { return formatEnd; }
	bool getSuccess() const { return success; }
};