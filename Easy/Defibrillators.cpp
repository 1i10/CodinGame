#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const float Pi = 3.1416f;
const float RadiusOfTheEarth = 6371.0f;

class Defibrillator
{
    private:
    int Ident;
    string Name;
    string Address;
    string ContactPhone;
    float Longitude;
    float Latitude;
    
    public:
    //Defibrillator();
    void SetParametresFromString(string InputInfo);
    string GetName() { return Name; }
    float GetLongitude() { return Longitude; }
    float GetLatitude() { return Latitude; }
};

float ConvertingStringToFloat(string FloatNumber);
float ConvertingDegreeToRadians(float NumberDegree);
Defibrillator DefibWithMinDistanceBetweenUser(vector<Defibrillator> Defibs, float UserLon, float UserLat);
float DistanceBetweenUserAndDefib(float LonA, float LatA, float LonB, float LatB);

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    vector<Defibrillator>Defibs(N);

    for (int i = 0; i < N; i++) 
    {
        string DefibInfo;
        getline(cin, DefibInfo);

        Defibs[i].SetParametresFromString(DefibInfo);
    }

    Defibrillator NearestDefib = DefibWithMinDistanceBetweenUser(Defibs, ConvertingStringToFloat(LON), ConvertingStringToFloat(LAT));
    
    cout << NearestDefib.GetName() << endl;
}

//Defibrillator::Defibrillator()
//{
//    Ident = -1;
//    Name = "-1";
//    Address = "-1";
//    ContactPhone = "-1";
//    Longitude = -1;
//    Latitude = -1;
//}

void Defibrillator::SetParametresFromString(string InputInfo)
{
    char Delim1 = ';';
    char Delim2 = '\n';

    int Start = 0;
    int End = InputInfo.find(Delim1);

    try
    {
        Ident = stoi(InputInfo.substr(Start, End));
    }
    catch(...)
    {
        Ident = -1;
    }
    
    InputInfo.erase(Start, End + 1);
    End = InputInfo.find(Delim1);

    Name = InputInfo.substr(Start, End);
    
    InputInfo.erase(Start, End + 1);
    End = InputInfo.find(Delim1);

    Address = InputInfo.substr(Start, End);
    
    InputInfo.erase(Start, End + 1);
    End = InputInfo.find(Delim1);

    ContactPhone = InputInfo.substr(Start, End);
    
    InputInfo.erase(Start, End + 1);
    End = InputInfo.find(Delim1);

    Longitude = ConvertingStringToFloat(InputInfo.substr(Start, End));
    
    InputInfo.erase(Start, End + 1);
    End = InputInfo.find(Delim2);

    Latitude = ConvertingStringToFloat(InputInfo);
}

float ConvertingStringToFloat(string FloatNumber)
{
    char Delim = ',';

    int PosDot = FloatNumber.find(Delim);
    
    return stof(FloatNumber.replace(PosDot, 1, "."));
}

float ConvertingDegreeToRadians(float NumberDegree)
{
    return NumberDegree * Pi/180.0f;
}

Defibrillator DefibWithMinDistanceBetweenUser(vector<Defibrillator> Defibs, float UserLon, float UserLat)
{
    vector<float>AllDistance;

    float UserLonRadians = ConvertingDegreeToRadians(UserLon);
    float UserLatRadians = ConvertingDegreeToRadians(UserLat);

    for (unsigned int i = 0; i < Defibs.size(); i++)
    {
        float DefibLonRadians = ConvertingDegreeToRadians(Defibs[i].GetLongitude());
        float DefibLatRadians = ConvertingDegreeToRadians(Defibs[i].GetLatitude());

        float Distance = DistanceBetweenUserAndDefib(UserLonRadians, UserLatRadians, DefibLonRadians, DefibLatRadians);

        AllDistance.push_back(Distance);

    }

    vector<float>::iterator MinDistance = min_element(AllDistance.begin(), AllDistance.end());

    int PosMinDistance = distance(AllDistance.begin(), MinDistance);

    return Defibs[PosMinDistance];
}

float DistanceBetweenUserAndDefib(float LonA, float LatA, float LonB, float LatB)
{
    float x = (LonB - LonA) * cos((LatA + LatB) / 2.0f);
    float y = LatB - LatA;

    float Distance = sqrt(x * x + y * y) * RadiusOfTheEarth;

    return Distance;
}