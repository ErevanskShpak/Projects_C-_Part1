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
	cout << "------Просмотр шести лучших игроков------\n";
	if (!isEmpty(vecHock)) //проверка на пустой файл записей о студентах
		return;
	sortHockByBest(vecHock);
	int amountOfBest = vecHock.size() > 6 ? 6 : vecHock.size();
	for (int i = 0; i < amountOfBest; i++)
	{
		outputHock(vecHock[i]);
		cout << "Результативость: " << vecHock[i].info.puck + vecHock[i].info.assist << endl;
	}
}