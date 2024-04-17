#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dist_to_opponent(int x, int y, int opp_x, int opp_y) {
    return sqrt((pow(opp_x - x, 2) + pow(opp_y - y, 2)));
}

int main() {
    bool have_boost = true;

    while (1) {
        int x;
        int y;
        int next_checkpoint_x;     // x position of the next check point
        int next_checkpoint_y;     // y position of the next check point
        int next_checkpoint_dist;  // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle;
        cin.ignore();
        int opponent_x;
        int opponent_y;
        cin >> opponent_x >> opponent_y;
        cin.ignore();

        /* Algorithm starts below */

        int target_x, target_y, target_abs_angle, target_dist;
        // int dto = dist_to_opponent(x, y, opponent_x, opponent_y);
        // if (dto <= 1000) {
        //     target_x = opponent_x;
        //     target_y = opponent_y;
        //     target_abs_angle = 0;
        //     target_dist = dto;
        // } else {
        //     target_x = next_checkpoint_x;
        //     target_y = next_checkpoint_y;
        //     target_abs_angle = abs(next_checkpoint_angle);
        //     target_dist = next_checkpoint_dist;
        // }
        target_x = next_checkpoint_x;
        target_y = next_checkpoint_y;
        target_abs_angle = abs(next_checkpoint_angle);
        target_dist = next_checkpoint_dist;

        int thrust = 100;
        bool ideal = false;
        if (target_abs_angle > 90) {
            thrust = 0;
        } else if (target_abs_angle > 75) {
            thrust = 25;
        } else if (target_abs_angle > 50) {
            thrust = 75;
        }
        if (target_abs_angle < 30 && target_dist >= 3000) {
            ideal = true;
        }

        if (have_boost && ideal) {
            have_boost = false;
            cout << target_x << " " << target_y << " BOOST" << endl;
        } else {
            cout << target_x << " " << target_y << " " << thrust << endl;
        }
    }
}
