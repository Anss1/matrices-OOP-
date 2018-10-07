//author : Dr.Mohammed El-Ramly
//Assignment 1 for programming II course (Individual)
//Faculty of computers and information Cairo university
//student name : Ans Saber Ahmed      ID : 20170391     group : 14
//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void Header(ofstream& out)
{
    out <<"<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
    out <<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
    out <<"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
    out <<"<svg width=\"500\" height=\"500\"" << endl;
    out <<"xmlns=\"http://www.w3.org/2000/svg\">" << endl << endl;

}

void DrawRect(int H_1, int H_2, int H_3, int H_4, ofstream& out)
{
    out <<"<rect x=\"20\"" << " y=" <<" \" "<< (400 - H_1) <<" \" " << " width=\"30\"" << " height=" <<"\" " << H_1 <<"\" " << endl;
    out << " style=\"fill:black;\"/> " << endl << endl;
    out <<"<rect x=\"80\"" << " y=" <<" \" "<< (400 - H_2) <<" \" " << " width=\"30\"" << " height=" <<"\" " << H_2 <<"\" " <<endl;
    out << " style=\"fill:black;\"/> " << endl << endl;
    out <<"<rect x=\"140\"" << " y=" <<" \" "<< (400 - H_3) <<" \" " << " width=\"30\"" << " height=" <<"\" " << H_3 <<"\" " << endl;
    out << " style=\"fill:black;\"/> " << endl << endl;
    out <<"<rect x=\"200\"" << " y=" <<" \" "<< (400 - H_4) <<" \" " << " width=\"30\"" << " height=" <<"\" " << H_4 <<"\" " << endl;
    out << " style=\"fill:black;\"/> " << endl << endl;


}

void DrawLine(ofstream& out)
{
    out << "<line x1=\"10\" y1=\"400\" x2=\"400\" y2=\"400\"" << endl
         << "style=\"stroke:black;stroke-width:3\"/>" <<endl << endl;

    out << "<line x1=\"10\" y1=\"400\" x2=\"10\" y2=\"10\""<< endl
         <<  "style=\"stroke:black;stroke-width:3\"/>"<< endl << endl;

    out << "</svg>" << endl;

}

int main()
{
    ofstream outSvg("Ans.svg");
    int height_1, height_2, height_3, height_4;
    cout<< "Note: height is ranged (0 - 400)." << endl;
    cout << "Enter Bars height : ";

    cin >> height_1 >> height_2 >> height_3 >> height_4;

        Header(outSvg);
        DrawRect(height_1, height_2, height_3, height_4, outSvg);
        DrawLine(outSvg);


return 0;
}



