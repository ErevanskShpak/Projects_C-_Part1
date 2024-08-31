#include "ElementHistory.h"

bool ElementHistory::isEditorCorrect() {
	if (!(editor[0] >= 'A' && editor[0] <= 'Z')) {
		return false;
	}

	size_t size = editor.size();
	for (int i = 1; i < size; ++i) {
		if (!(editor[i] >= 'a' && editor[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

void ElementHistory::setEditor() {
	cout << "Input editor: ";
	getline(cin, editor, '\n');
	while (!isEditorCorrect()) {
		cout << "Invalid input, please try again. The editor must be without spaces, consist only of letters and begin with a capital letter\n";
		getline(cin, editor, '\n');
	}
}