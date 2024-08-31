#include "individualModule.h"

void sortHockByBest(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByBest);
}

bool partSortByBest(Hockey hockA, Hockey hockB)
{
	return (hockA.info.puck + hockA.info.assist) > (hockB.info.puck + hockB.info.assist);
}

void showByBest(vector<Hockey> vecHock)
{
	cout << "------�������� ����� ������ �������------\n";
	if (!isEmpty(vecHock)) //�������� �� ������ ���� ������� � ���������
		return;
	sortHockByBest(vecHock);
	int amountOfBest = vecHock.size() > 6 ? 6 : vecHock.size();
	for (int i = 0; i < amountOfBest; i++)
	{
		outputHock(vecHock[i]);
		cout << "���������������: " << vecHock[i].info.puck + vecHock[i].info.assist << endl;
	}
}