class Solution {
public:
    bool isLeapYear(int year) {
        if(year%4==0) {
            if(year%100==0) {
                if(year%400 == 0) return true;
                else return false;
            } else {
                return true;
            }
        }

        return false;
    }
    
    int DaysInMonth(int month, int year) {
        if(month==2) {
            return isLeapYear(year) ? 29:28;
        }
        
        switch(month) {
            case 1:
                return 31;
            case 3:
                return 31;
            case 4:
                return 30;
            case 5:
                return 31;
            case 6:
                return 30;
            case 7:
                return 31;
            case 8:
                return 31;
            case 9:
                return 30;
            case 10:
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
        }
        
        return 30;
    }

    // function to find the number of days in a year.
    int DaysInYear(int year) {
        if(isLeapYear(year)) return 366;
        else return 365;
    }

    // function to calculate days passed in a year.
    int DaysPassedInYear(int year, int month, int day) {
        int days = 0;
        for(int i=1; i<month; i++) {
            days += DaysInMonth(i, year);
        }
        days+=day;

        return days;
    }

    /*
     * Complete the function below.
     */
    int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) {
        int totalDays = 0;

        for(int i=year1+1; i<=year2-1; i++) {
            totalDays += DaysInYear(i);
        }
        
        if(year1 != year2) {
            totalDays += (DaysInYear(year1)-DaysPassedInYear(year1, month1, day1));

            totalDays += DaysPassedInYear(year2, month2, day2);
        } else {
            totalDays += DaysPassedInYear(year2, month2, day2) - DaysPassedInYear(year1, month1, day1);
        }

        return totalDays;
    }
    
    int daysBetweenDates(string date1, string date2) {
        int year1 = stoi(date1.substr(0,4));
        int month1 = stoi(date1.substr(5,2));
        int day1 = stoi(date1.substr(8,2));
        int year2 = stoi(date2.substr(0,4));
        int month2 = stoi(date2.substr(5,2));
        int day2 = stoi(date2.substr(8,2));
        
        if(year1>year2 || (year1==year2 && month1>month2) || (year1==year2 && month1==month2 && day1>day2))
            return DaysBetween(year2, month2, day2, year1, month1, day1);
        
        return DaysBetween(year1, month1, day1, year2, month2, day2);
    }
};