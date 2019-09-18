#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    int x_e = 0, y_e = 0;
    int x_i, y_i;
    string lost;
    string instruct, direct;
    vector<pair<int, int>> nums;

    cin >> x_e >> y_e;

    while (cin >> x_i >> y_i >> direct) {
        cin >> instruct;
        lost = "";
        auto n = instruct.length();
        for (int i = 0; i < n; i++) {
            switch (instruct[i]) {
                case 'L': {
                    switch (direct[0]) {
                        case 'N': {
                            if (lost != " LOST") direct[0] = 'W';
                        }
                            break;
                        case 'W': {
                            if (lost != " LOST") direct[0] = 'S';
                        }
                            break;
                        case 'S': {
                            if (lost != " LOST") direct[0] = 'E';
                        }
                            break;
                        case 'E': {
                            if (lost != " LOST") direct[0] = 'N';
                        }
                            break;
                    }
                }
                    break;

                case 'R': {
                    switch (direct[0]) {
                        case 'N': {
                            if (lost != " LOST") direct[0] = 'E';
                        }
                            break;
                        case 'W': {
                            if (lost != " LOST") direct[0] = 'N';
                        }
                            break;
                        case 'S': {
                            if (lost != " LOST") direct[0] = 'W';
                        }
                            break;
                        case 'E': {
                            if (lost != " LOST") direct[0] = 'S';
                        }
                            break;
                    }
                }
                    break;

                case 'F': {
                    switch (direct[0]) {
                        case 'N' : { //x,y+1
                            if (y_i > y_e) {
                                y_i = y_e;
                                lost = " LOST";
                            } else if (y_i < 0) {
                                lost = " LOST";
                            } else {
                                y_i++;
                                if (y_i > y_e) {
                                    lost = " LOST";
                                    y_i = y_e;
                                }
                            }
                        }
                            break;

                        case 'W' : { //x-1,y
                            if (x_i > x_e) {
                                lost = " LOST";
                            } else if (x_i < 0) {
                                lost = " LOST";
                                x_i = 0;
                            } else {
                                x_i--;
                                if (x_i < 0) {
                                    lost = " LOST";
                                    x_i = 0;
                                }
                            }
                        }
                            break;

                        case 'S' : { //x,y-1
                            if (y_i > y_e) {
                                lost = " LOST";
                            } else if (y_i < 0) {
                                y_i = 0;
                                lost = " LOST";
                            } else {
                                y_i--;
                                if (y_i < 0) {
                                    lost = " LOST";
                                    y_i = 0;
                                }
                            }
                        }
                            break;

                        case 'E' : { //x+1,y
                            if (x_i > x_e) {
                                lost = " LOST";
                                x_i = x_e;
                            } else if (x_i < 0) {
                                lost = " LOST";
                            } else {
                                x_i++;
                                if (x_i > x_e) {
                                    lost = " LOST";
                                    x_i = x_e;
                                }
                            }
                        }
                            break;
                    }
                }
                    break;
            }
        }
        if (x_i > x_e) {
            x_i = x_e;
            lost = " LOST";
        } else if (x_i < 0) {
            x_i = 0;
            lost = " LOST";
        }

        if (y_i > y_e) {
            y_i = y_e;
            lost = " LOST";
        } else if (y_i < 0) {
            y_i = 0;
            lost = " LOST";
        }

        cout << x_i << " " << y_i << " " << direct[0] << lost << endl;
        //nums.push_back(make_pair(x_i, y_i));
    }

    //for(auto elem: nums)
    //    cout<<elem.first<<" "<<elem.second<<endl;

    return 0;
}