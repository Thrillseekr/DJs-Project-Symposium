#include <bits/stdc++.h>
using namespace std;

class car

{
    char yn;
    int choise, i, num;
    string availability, fuel;
    string Password, id, ps, dest, date;
    string ad_Car_name, car_name[15], c[15], hst[15];

public:
    string Id;

    /*if "Id" (or any other vatiable) is made public, any function a can use it by only initialising once
    as it is initialised only in line (31) and will used by other functions like book(),history()*/

    int rent_fare, total_fare, distance, fare_per_km, time_conjestion;

    void login_register()
    {
        cin >> choise;

        switch (choise)
        {
        case 1:
        {
            cout << "\n -------> * logMeIn * <-------    " << endl;

            cout << "\nEnter User Id : ";
            cin >> Id;
            cout << "Enter Password : ";
            cin >> Password;

            ifstream read("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/REGISTRATION DETAILS/" + Id + ".txt");
            /* Add the path of your file where you stored/saved your credentials*/ 
            read >> id;
            read >> ps;

            read.close();

            if ((Id == id) && (Password == ps))
            {
                cout << "\nKudos.... \nSuccessfully LoggedIn !!\a\a" << endl;
            }

            else
            {
                cout << "\nOops.... \nWrong Id or Password !! \n\n\a\a";
                cout << "\n\n                        ** Thanks for Visiting **\n\n\n\n\a\a" << endl;
                exit(0);
            }
        }
        break;

        case 2:
        {
            cout << "\n -------> * Register * <-------   " << endl;
            cout << "\nEnter User Id : ";
            cin >> Id;
            cout << "Enter Password : ";
            cin >> Password;

            ofstream write("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/REGISTRATION DETAILS/" + Id + ".txt");
            /* Add the path of your file in which you have to store/save your credentials*/ 
            write << Id << endl;
            write << Password << endl;

            write.close();

            cout << "\nKudos.... \nSuccessfully Registered !!\a\a" << endl;
        }
        break;

        default:
            cout << "\n Oops.... \nInvalid Choise !!\a\a" << endl;
        }
    }

    void set_detail()
    {
        cout << "\nEnter Car Name: ";
        cin >> ad_Car_name;

        ofstream dt_write("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/CAR DETAILS/ " + ad_Car_name + ".txt");
        /* Add the path of your file in which you have to store/save Car Details*/  
        
        ofstream c_write("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/CAR DETAILS/car-list.txt", ios::app);
        /* Add the path of your file in which you have to add car details*/ 
        c_write << "\n"
                << ad_Car_name; // c_write dose'nt read spaces, so first space is not read by program

        dt_write << ad_Car_name << endl;

        cout << "\nEnter Availability : ";
        cin >> availability;
        dt_write << availability << endl;

        cout << "Enter Rent Fare : ";
        cin >> rent_fare;
        dt_write << rent_fare << endl;

        cout << "Enter Fare/km : ";
        cin >> fare_per_km;
        dt_write << fare_per_km << endl;

        cout << "Enter Time Conjestion : ";
        cin >> time_conjestion;
        dt_write << time_conjestion << endl;

        cout << "Enter Fuel (P / D) : ";
        cin >> fuel;
        dt_write << fuel << endl;

        dt_write.close();
        // copy.close();
    }

    void count()
    {
        ifstream cnt("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/CAR DETAILS/car-list.txt");
        for (i = 0; cnt.eof() == 0; ++i)
        {
            cnt >> car_name[i];
        }
        num = i;
        cout << num << " Cars \n"
             << endl;
    }

    void car_list()
    {
        count();

        ifstream read_car("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/CAR DETAILS/car-list.txt");
        for (int i = 0; read_car.eof() == 0; ++i)
        {
            read_car >> car_name[i];
            c[i] = car_name[i];
            cout << "**************\a\a" << endl;
            cout << (i + 1) << ". " << c[i] << endl;
        }
        cout << "**************" << endl;

        read_car.close();
    }

    void get_detail()
    {
        cin >> i;

        ifstream dt_read("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/CAR DETAILS/ " + c[i - 1] + ".txt");

        dt_read >> c[i - 1];
        cout << endl
             << "      "
             << "===\" " << c[i - 1] << "\"===" << endl;

        dt_read >> availability;
        cout << "\nAvailability : " << availability << endl;

        dt_read >> rent_fare;
        cout << "Rent Fare (per day) : " << rent_fare << endl;

        dt_read >> fare_per_km;
        cout << "Fare/km : " << fare_per_km << endl;

        dt_read >> time_conjestion;
        cout << "Time Conjestion : " << time_conjestion << endl;

        dt_read >> fuel;
        cout << "Fuel : " << fuel << endl;

        cout << "\n\n\tBook " << c[i - 1] << " ?? (Y/N) : ";
    }

    float t_fare()
    {
        total_fare = (rent_fare) + (fare_per_km * distance) + (time_conjestion);
        cout << "\nApprox. Total fare "
             << "for \"" << c[i - 1] << "\" is : " << endl;
        cout << "      *    " << endl;
        cout << "   *     * " << endl;
        cout << "* Rs." << total_fare << "  *" << endl;
        cout << "   *     * " << endl;
        cout << "      *    \a\a" << endl;
        cout << "\nnote : Time Conjestion Charges are not included." << endl;

        return 0; // since it is a non-void function
    }

    void book()

    {
        cin >> yn;

        if ((yn == 'y') || (yn == 'Y'))
        {

            ofstream book_cr("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/REGISTRATION DETAILS/" + Id + ".txt", ios::app);

            book_cr << "\n"
                    << c[i - 1] << endl;
            cout << "\n"
                 << "===* " << c[i - 1] << " *=== " << endl;

            cout << "\nEnter Date of Journey (dd/mm/yy) : ";
            cin >> date;
            book_cr << date << endl;

            cout << "Enter Destination : ";
            cin >> dest;
            book_cr << dest << endl;

            cout << endl
                 << "Enter Distance b/w Pickup and Drop location(in km) : ";
            cin >> distance;
            book_cr << distance << " km" << endl;

            total_fare = (rent_fare) + (fare_per_km * distance) + (time_conjestion);
            book_cr << "Rs." << total_fare << endl;

            cout << "\n\tWooHoooo....\n"
                 << "\"" << c[i - 1] << "\""
                 << " Successfully Booked !!\a\a" << endl;

            t_fare();
        }
        else
            ;
    }

    void history()
    {
        cout << "\nWanna check Order History ?? (Y/N) : ";
        cin >> yn;
        if ((yn == 'Y') || (yn == 'y'))
        {
            cout << "\n====* Your History *===  \n\n";

            ifstream hst_read("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/REGISTRATION DETAILS/" + Id + ".txt");

            for (i = 0; hst_read.eof() == 0; ++i)
            {
                getline(hst_read, hst[i]);

                if (i >= 3)
                {
                    cout << hst[i] << endl;
                }
                else
                    ;
            }

            cout << "\nContinue (Y/N) : ";
            cin >> yn;
            if ((yn == 'Y') || (yn == 'y'))
                ;
            else
            {
                cout << "\n\n                        ** Thanks for Visiting **\n\n\n\n \a\a\a\a\a\a\a\a" << endl;
                exit(0);
            };
        }
        else
            ;
    }
};

int main()
{

    car ob;
    char yn;
    int choise, i, entry;
    string Id, usr, id, Password, ps, adps, ad_key, key;
    string ad_Car_name, fuel, availability, car_name[15];
    int rent_fare, fare_per_km, time_conjestion, distance;

    cout << "\n\n\a\a\a\a\a\a\a\a";
    cout << "                                ##############################" << endl;
    cout << "                            *****   Welcome @ Gaddi Udhaar  *****" << endl;
    cout << "                                ##############################" << endl;
    cout << "                 \"We provide Car of different types on RENT at a Minimal Cost\" " << endl;

    cout << "\n\n1. Admin" << endl;
    cout << "2. User" << endl;

    cout << "\nEnter choise : " << endl;
    cout << "    *    " << endl;
    cout << " *     * " << endl
         << "    ";
    cin >> choise;
    cout << " *     * " << endl;
    cout << "    *    " << endl;

    //------------------- 1. Admin User choise done -----------------------

    if (choise == 1)
    {
        cout << "\n\n -------> * ADMIN * <-------" << endl;

        cout << "\nWant to set new Key ?? (Y/N) : ";
        cin >> yn;

        if ((yn == 'y') || (yn == 'Y'))
        {
            cout << "\nEnter Current Key : ";
            cin >> key;
            ifstream aread("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/admin.txt");
            aread >> adps;

            if (key == adps)
            {
                cout << "\nEnter New Key : ";
                cin >> ad_key;

                ofstream awrite("G:/COLLEGE/CODING/C++/C++ PROGRAMMING/PROJECTS/CAR RENTAL SYSTEM MANAGEMENT PROJECT/admin.txt");
                awrite << ad_key;

                awrite.close();
                cout << "\n// New Key Successfully Set \\\\ \a\a";
            }

            else
            {
                cout << "\nOops....\n Invalid Key !!\a\a" << endl;
                // exit(0);
            }
        }

        else if ((yn == 'n') || (yn == 'N'))
        {
            cout << "\nEnter Current Key : ";
            cin >> key;
            ifstream aread("admin.txt");
            aread >> adps;

            aread.close();

            if (key == adps)
            {
                cout << "\n     $ WELCOME $ \n\a\a";
                cout << "\nNo of cars to Register : ";
                cin >> entry;
                for (i = 0; i < entry; ++i)
                {
                    ob.set_detail();
                }
            }

            else
            {
                cout << "\nOops.... \nInvalid Key !!\n \a\a" << endl;
            }
        }
    }

    //------------------- 2. Admin part done -----------------------

    else if (choise == 2)
    {
        cout << "\n1. Existing User" << endl;
        cout << "2. New User" << endl;

        cout << "\nEnter choise : ";

        ob.login_register();

        ob.history();

        cout << "\n\n";
        cout << "                       ************" << endl;
        cout << "                 ------> Our Cars <------ " << endl;
        cout << "                       ************\a\a\a\a" << endl;

        cout << "We have ";

        ob.car_list();

        cout << "\nEnter Car no. for details : ";
        ob.get_detail();

        ob.book();

        cout << "\n\nWant to Search Next ?? (Y/N) : ";
        cin >> yn;
        while ((yn == 'y') || (yn == 'Y'))
        {
            cout << "\nSearch Car No. : ";

            ob.get_detail();

            ob.book();

            cout << "\n\nWant to Search Next ?? (Y/N) : ";
            cin >> yn;
        }
    }

    else
    {
        cout << "\nOops.... \nInvalid Choise !!\a\a" << endl;
    }

    cout << "\n\n                        ** Thanks for Visiting **\n\n\n\n \a\a\a\a\a\a\a\a" << endl;

    return 0;
}
