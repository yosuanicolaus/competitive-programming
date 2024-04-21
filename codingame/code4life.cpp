#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum State {
    COLLECTING_SAMPLE,
    COLLECTING_MOLECULE,
    DELIVERING,
};

enum Location { DIAGNOSIS, MOLECULES, LABORATORY };

map<Location, string> location_name{
    {DIAGNOSIS, "DIAGNOSIS"},
    {MOLECULES, "MOLECULES"},
    {LABORATORY, "LABORATORY"},
};

struct Sample {
    int sample_id;
    int carried_by;
    int cost_a, cost_b, cost_c, cost_d, cost_e;
    int health;
    bool diagnosed;

    int total_cost() const {
        return cost_a + cost_b + cost_c + cost_d + cost_e;
    }
    double value() const {
        return (double)health / total_cost();
    }
};

/**
 * Bring data on patient samples from the diagnosis machine to the laboratory with enough molecules to produce medicine!
 **/

int main() {
    int project_count;
    cin >> project_count;
    cin.ignore();
    for (int i = 0; i < project_count; i++) {
        int a;
        int b;
        int c;
        int d;
        int e;
        cin >> a >> b >> c >> d >> e;
        cin.ignore();
    }

    bool first_turn = true;
    Location location = DIAGNOSIS;
    State state = COLLECTING_SAMPLE;
    set<int> taken_by_opponent;
    deque<Sample> available_samples;
    int carried_molecule_count = 0; // max 10
    int cma = 0, cmb = 0, cmc = 0, cmd = 0, cme = 0;
    vector<Sample> carried_samples; // max 3

    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            string target;
            int eta;
            int score;
            int storage_a;
            int storage_b;
            int storage_c;
            int storage_d;
            int storage_e;
            int expertise_a;
            int expertise_b;
            int expertise_c;
            int expertise_d;
            int expertise_e;
            cin >> target >> eta >> score >> storage_a >> storage_b >> storage_c >> storage_d >> storage_e >>
                expertise_a >> expertise_b >> expertise_c >> expertise_d >> expertise_e;
            cin.ignore();
        }
        int available_a;
        int available_b;
        int available_c;
        int available_d;
        int available_e;
        cin >> available_a >> available_b >> available_c >> available_d >> available_e;
        cin.ignore();
        int sample_count;
        cin >> sample_count;
        cin.ignore();
        for (int i = 0; i < sample_count; i++) {
            int sample_id;
            int carried_by;
            int rank;
            string expertise_gain;
            int health;
            int cost_a;
            int cost_b;
            int cost_c;
            int cost_d;
            int cost_e;
            cin >> sample_id >> carried_by >> rank >> expertise_gain >> health >> cost_a >> cost_b >> cost_c >>
                cost_d >> cost_e;
            cin.ignore();

            if (first_turn) {
                Sample smp = {sample_id, carried_by, cost_a, cost_b, cost_c, cost_d, cost_e, health, false};
                available_samples.push_back(smp);
            }
            if (carried_by == 1) { // taken by opponent
                for (auto &s : available_samples) {
                    if (s.sample_id == sample_id) {
                        s.carried_by = 1;
                        break;
                    }
                }
            }
        }

        if (first_turn) {
            sort(available_samples.rbegin(), available_samples.rend(),
                 [](const Sample &a, const Sample &b) { return a.value() < b.value(); });
            first_turn = false;
            cout << "GOTO DIAGNOSIS" << endl;
            continue;
        }

        if (state == COLLECTING_SAMPLE) {
            if (location != DIAGNOSIS) {
                location = DIAGNOSIS;
                cout << "GOTO DIAGNOSIS" << endl;
            } else if (carried_samples.size() > 0) { // have 1 sample, later we'll improve here
                state = COLLECTING_MOLECULE;
                location = MOLECULES;
                cout << "GOTO MOLECULES" << endl;
            } else {
                auto s = available_samples.front();
                available_samples.pop_front();
                int scb = s.carried_by;
                while (scb != -1) {
                    s = available_samples.front();
                    available_samples.pop_front();
                    scb = s.carried_by;
                }

                carried_samples.push_back(s);
                cout << "CONNECT " << s.sample_id << endl;
            }
        } else if (state == COLLECTING_MOLECULE) {
            if (location != MOLECULES) {
                location = MOLECULES;
                cout << "GOTO MOLECULES" << endl;
            } else {
                auto s = carried_samples[0];
                if (cma < s.cost_a) {
                    cma++;
                    cout << "CONNECT A" << endl;
                } else if (cmb < s.cost_b) {
                    cmb++;
                    cout << "CONNECT B" << endl;
                } else if (cmc < s.cost_c) {
                    cmc++;
                    cout << "CONNECT C" << endl;
                } else if (cmd < s.cost_d) {
                    cmd++;
                    cout << "CONNECT D" << endl;
                } else if (cme < s.cost_e) {
                    cme++;
                    cout << "CONNECT E" << endl;
                } else {
                    location = LABORATORY;
                    state = DELIVERING;
                    cout << "GOTO LABORATORY" << endl;
                }
            }
        } else { // state == LABORATORY
            if (location != LABORATORY) {
                location = LABORATORY;
                cout << "GOTO LABORATORY" << endl;
            } else {
                if (carried_samples.size() > 0) {
                    auto s = carried_samples.back();
                    cma -= s.cost_a;
                    cmb -= s.cost_b;
                    cmc -= s.cost_c;
                    cmd -= s.cost_d;
                    cme -= s.cost_e;
                    carried_samples.pop_back();
                    cout << "CONNECT " << s.sample_id << endl;
                } else {
                    location = DIAGNOSIS;
                    state = COLLECTING_SAMPLE;
                    cout << "GOTO DIAGNOSIS" << endl;
                }
            }
        }
    }
}
