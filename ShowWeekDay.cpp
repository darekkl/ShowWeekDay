#include "ShowWeekDay.h"
#include <iostream>
//#include <memory>

using namespace std;

bool ShowWeekDay::CheckIfLeapYear(uint16_t Year) {
	if (Year % 4 == 0 && Year % 100 != 0)
		return true;
	else if (Year % 4 == 0 && Year % 400 == 0)
		return true;

	return false;
}

bool ShowWeekDay::CheckIfDateIsLaterThanTemplate() {
	if (mYear > mYearTemplate)
		return true;
	if (mYear == mYearTemplate && mMonth > mMonthTemplate)
		return true;
	if (mYear == mYearTemplate && mMonth == mMonthTemplate
			&& mDay > mDayTemplate)
		return true;

	return false;
}

uint16_t ShowWeekDay::CountWeekDayForLaterDate() {
	auto year = mYearTemplate;
	auto month = mMonthTemplate;
	auto day = mDayTemplate;
	uint16_t weekDayNumber = 0;

	while (year < mYear || month < mMonth || day < mDay) {
		if (month == 2 && CheckIfLeapYear(year)
				&& day < (mRegularYear[month - 1] + 1)) // luty/przestępny
						{
			++day;
			++weekDayNumber;
		} else if (day < mRegularYear[month - 1]) {
			++day;
			++weekDayNumber;
		} else {
			day = 1;
			++month;
			if (month > mMonthCount) {
				month = 1;
				++year;
			}
			++weekDayNumber;
		}
	}

	if (weekDayNumber > 0)
		weekDayNumber %= mWeekDaysNum;

	return weekDayNumber;
}

uint16_t ShowWeekDay::CountWeekDayForEarlierDate() {
	uint16_t year = mYearTemplate;
	uint16_t month = mMonthTemplate;
	uint16_t day = mDayTemplate;
	uint16_t weekDayNumber = 0;

	while (year > mYear || month > mMonth || day > mDay) {
		if (day > 1) {
			--day;
			++weekDayNumber;
		} else {
			--month;
			if (month < 1) {
				month = mMonthCount;
				--year;
			}
			++weekDayNumber;
			day = mRegularYear[month - 1];

			if (month == 2 && CheckIfLeapYear(year) == true) // February
				++day;
		}
	}

	if (weekDayNumber > 0)
		weekDayNumber %= mWeekDaysNum;
	if (weekDayNumber > 0)
		weekDayNumber = static_cast<uint16_t>(mWeekDaysNum - weekDayNumber);

	return weekDayNumber;
}

bool ShowWeekDay::SetYearMonthDay() {
	uint16_t Year;
	uint16_t Month;
	uint16_t Day;

	cout << "Program oblicza, jaki dzień tygodnia był w dniu o podanej dacie."
			<< endl;
	cout << "Podaj rok (np.1999):" << endl;
	cin >> Year;
	cout << "Podaj miesiąc (1-12): " << endl;
	cin >> Month;
	cout << "Podaj dzień (1-31): " << endl;
	cin >> Day;

	return SetYearMonthDay(Year, Month, Day);
}

bool ShowWeekDay::CountWeekDay() {

	if (CheckIfDateIsLaterThanTemplate() == true)
		mWeekDayNumber = CountWeekDayForLaterDate();
	else
		mWeekDayNumber = CountWeekDayForEarlierDate();

	return true;
}

bool ShowWeekDay::ShowDayName() {
	if (mWeekDayNumber >= mWeekDaysNum) {
		cout << "Incorrect mWeekDayNumber = " << mWeekDayNumber << endl;
		return false;
	}

	cout << "Dzień = " << mWeekDayName[mWeekDayNumber] << endl;

	return true;
}

bool ShowWeekDay::SetYearMonthDay(uint16_t Year, uint16_t Month, uint16_t Day) {
	if(Month > 12 || Day > 31)
		return false;

	mYear = Year;
	mMonth = Month;
	mDay = Day;

	return true;
}

uint16_t ShowWeekDay::GetWeekDayNumber() {
	return mWeekDayNumber;
}
