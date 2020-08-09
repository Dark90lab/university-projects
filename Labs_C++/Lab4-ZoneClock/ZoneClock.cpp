#include <iostream>
using namespace std;
#include "ZoneClock.h"

int ZoneClock::clock_number = 0;

ZoneClock::ZoneClock(int _hour, int _min, clock_period period)
{
	clock_number++;
		hour = _hour;
		min = _min;
		this->period = period;
		if (clock_number % 3 == 0)
		{
			if (period == clock_period::pm && hour != 12)
				hour += 12;
			if (period == clock_period::am && hour == 12)
				hour = 0;
			format = false;
		}
}

ostream& operator<<(std::ostream& out, const ZoneClock& c)
{
	 if (c.format == true)
	 {
		 if (c.hour < 10)
			 out << "0" << c.hour << ":";
		 else
			 out << c.hour << ":";
		 if (c.min < 10)
			 out << "0" << c.min;
		 else
			 out<<c.min;
		 if (c.period == clock_period::am)
			 out << "am";
		 else
			 out << "pm";

	 }
	 else
	 {

		 if (c.hour < 10)
			 out << "0" << c.hour << ":";
		 else
			 out << c.hour << ":";
		 if (c.min < 10)
			 out << "0" << c.min;
		 else
			 out << c.min;;

	 }

	 //part 5
	 if (c.zone == time_zone::UTC || c.zone == time_zone::WET)
		 out << " UTC + 0" << endl;
	 if (c.zone == time_zone::CET)
		 out << " UTC + 1" << endl;
	 if (c.zone == time_zone::EET)
		 out << " UTC + 2" << endl;


	 return out;
}

 istream& operator>>(std::istream& in, ZoneClock& c)
 {
	 char buffer[3];
	 buffer[2] = '\0';
	 do
	 {
		 cout << "Enter hour:";
		 cin >> c.hour;
		 cout << "Enter minutes:";
		 cin >> c.min;
		 cout << "Enter (am/pm):";
		 cin >> buffer;
		 if (!strcmp(buffer, "am") && (c.hour > 12))
		 {
			 cout << "Wrong time!" << endl;
		 }
	 } while ((!strcmp(buffer,"am")&&(c.hour>12)));
	 if (!strcmp(buffer, "am"))
		 c.period = clock_period::am;
	 else
		 c.period = clock_period::pm;
	 c.clock_number++;

	 if (c.clock_number % 3 == 0)
	 {
		 if (c.period == clock_period::pm && c.hour != 12)
			 c.hour += 12;
		 if (c.period == clock_period::am && c.hour == 12)
			 c.hour = 0;
		 c.format = false;
	 }


	 return in;

 }

 void  ZoneClock::add_minute()
 {
	 min++;
	 if (format == true)
	 {
		 if (min == 60)
		 {
			 if (hour == 12)//12:60
			 {
				 hour = 1;
				 min = 0;
			 }
			 else if (hour == 11 && period == clock_period::am)
			 {
				 period = clock_period::pm;
				 hour++;
				 min = 0;
			 }
			 else if (hour == 11 && period == clock_period::pm)
			 {
				 hour++;
				 period = clock_period::am;
				 min = 0;
			 }
			 else
			 {
				 hour++;
				 min = 0;
			 }
		 }
	 }
	 else
	 {
		 if (min == 60&& hour ==23)
		 {
			 hour=0;
			 min = 0;
		 }
		 else if(min==60)
		 {
			 hour++;
			 min = 0;
		 }
	 }
 }

 void  ZoneClock::add_minutes(int minutes)
 {

	 for (int i = 0; i < minutes; i++)
	 {
		 add_minute();
		 
	 }


 }

 void ZoneClock::subtract_minute()
 {
	 min--;
	 if (format == true)
	 {
		 if (min<0)
		 {
			 if (hour == 1)//12:60
			 {
				 hour = 12;
				 min = 59;
			 }
			 else if (hour == 12 && min<0 && period == clock_period::pm)
			 {
				 period = clock_period::am;
				 hour=11;
				 min = 59;
			 }
			 else if (hour == 12 && min<0 && period == clock_period::am)
			 {
				 hour=11;
				 period = clock_period::pm;
				 min = 59;
			 }
			 else
			 {
				 hour--;
				 min = 59;
			 }
		 }
	 }
	 else
	 {
		 if (min <0 && hour == 0)
		 {
			 hour = 23;
			 min = 59;
		 }
		 else if (min <0)
		 {
			 hour--;
			 min = 59;
		 }
	 }
 }

 void  ZoneClock::subtract_minutes(int minutes)
 {
	 for (int i = 0; i < minutes; i++)
	 {
		 subtract_minute();

	 }

 }

 void ZoneClock::set_time_zone(const time_zone& tz)
 {
	 if((zone == time_zone::UTC && tz == time_zone::UTC))
		 return;
	 if ((zone ==time_zone::UTC || zone == time_zone::WET) && tz == time_zone::WET)
		 zone = time_zone::WET;
	 if ((zone == time_zone::UTC || zone == time_zone::WET) && tz == time_zone::CET)
	 {
		 zone = time_zone::CET;
		 add_minutes(60);
	 }
	 if ((zone == time_zone::UTC || zone == time_zone::WET) && tz == time_zone::EET)
	 {
		 zone = time_zone::EET;
		 add_minutes(120);
	 }

	 if ((zone == time_zone::CET && (tz == time_zone::WET || zone == time_zone::UTC)))
	 {
		 zone = time_zone::UTC;
		 subtract_minutes(60);
	 }
	 if ((zone == time_zone::CET || zone == time_zone::WET) && tz == time_zone::EET)
	 {
		 zone = time_zone::CET;
		 add_minutes(60);
	 }

	 if ((zone == time_zone::EET && (tz == time_zone::WET || zone == time_zone::UTC)))
	 {
		 zone = time_zone::UTC;
		 subtract_minutes(120);
	 }
	 if (zone == time_zone::EET && tz == time_zone::CET)
	 {
		 zone = time_zone::CET;
		 subtract_minutes(60);
	 }


 }

