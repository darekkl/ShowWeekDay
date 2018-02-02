#ifndef SHOW_WEEKDAY_H_
#define SHOW_WEEKDAY_H_

#include <array>

class ShowWeekDay
{
public:
	ShowWeekDay() :
			mYear(0), mMonth(0), mDay(0), mWeekDayNumber(0)
	{
	}
	~ShowWeekDay()
	{
	}
	bool SetYearMonthDay();
	bool CountWeekDay();
	bool ShowDayName();
	bool SetYearMonthDay(uint16_t Year, uint16_t Month, uint16_t Day);
	uint16_t GetWeekDayNumber();
private:
	bool CheckIfLeapYear(uint16_t Year);
	bool CheckIfDateIsLaterThanTemplate();
	uint16_t CountWeekDayForLaterDate();
	uint16_t CountWeekDayForEarlierDate();

	static const uint16_t mWeekDaysNum = 7;
	static const uint16_t mMonthCount = 12;
	uint16_t mYear;
	uint16_t mMonth;
	uint16_t mDay;
	uint16_t mWeekDayNumber;
	const uint16_t mYearTemplate = 2000;
	const uint16_t mMonthTemplate = 1;
	const uint16_t mDayTemplate = 2;
	const std::array<const uint16_t, mMonthCount> mRegularYear =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const std::array<const char*, mWeekDaysNum> mWeekDayName =
	{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
			"Saturday" };
};

#endif /* SHOW_WEEKDAY_H_ */
