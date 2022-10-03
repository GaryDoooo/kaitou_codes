#include <iostream>
#define STEP_TIME 0.01
#define SIM_LENGTH 60
using namespace std;

////// Input Status/////
int atk                    = 1563;
double crit_rate           = .483;
double crit_dmg            = .741;
double normal_attack_bonus = .2;
/// Kaeya
// int combo_ttl                 = 5;
// double combo_cooldown[5]   = {0.36, 0.36, 0.9, 0.93, 0.72};
// double combo_percentage[5] = {.581, .559, .706, .766, .954};
// Venti
// int combo_ttl                 = 6;
// double combo_cooldown[6]      = {0.58, .74, .43, .61, .86, 1.05};
// double combo_percentage[6]    = {.554, .604, .713, .71, .689, .965};
// double skill_1_cooldown       = 6;
// double skill_1_cast_time      = .38;
// int skill_1_combo_lower_bound = 0;
// double skill_1_dmg            = 3.45;
// Venti charged only
// int combo_ttl = 6;
// double combo_cooldown[6]      = {.724, .724, .724, .724, .724, .724};
// double combo_cooldown[6]      = {1, 1, 1, 1, 1, 1};
// double combo_percentage[6]    = {.991, .911, .991, .991, .991, .991};
// double skill_1_cooldown       = 6;
// double skill_1_cast_time      = .38;
// int skill_1_combo_lower_bound = 6;
// double skill_1_dmg            = 3.45;
// double oz_time                = 10;
// double no_oz_bonus            = 1;
// Fischl
int combo_ttl                 = 5;
double combo_cooldown[5]      = {.31, .69, .83, .43, 1.02};
double combo_percentage[5]    = {.6, .636, .791, .785, .98};
double skill_1_cooldown       = 25;
double skill_1_cast_time      = .54;
int skill_1_combo_lower_bound = 4;
double skill_1_dmg            = 1.44;
double oz_time                = 10;
double oz_atk_ratio           = 1.11;
double oz_atk_cooldown        = .816;
double no_oz_bonus            = 1.22;
double full_charge_time       = 1.65;
double oz_thunder_ratio       = 1.64 * 1.527;
bool charge_atk_oz            = true;
int enemy_count               = 2;
////
//
//////Timer//////
double combo_CD_timer        = 0;  // Timer
double skill_black_out_timer = 0;
double skill_1_CD_timer      = 0;
double oz_timer              = 0;
double oz_atk_timer          = 0;
double full_charge_timer     = 0;
///
//
/////Simulation status/////
double ttl_damage            = 0;
bool charging                = false;
int oz_atk_count             = 0;
double ttl_oz_damage         = 0;
double thunder_dmg           = 0;
int thunder_count            = 0;
int combo_count              = 0;
int skill_1_counter          = 0;
int normal_attack_counter[6] = {0, 0, 0, 0, 0, 0};
///
//
////// Simulation functions
void normal_attack() {
    double base_damage =
        atk * combo_percentage[combo_count] * normal_attack_bonus;
    if (oz_timer <= 0) base_damage *= no_oz_bonus;
    ttl_damage +=
        base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
}

void skill_1() {
    double base_damage = skill_1_dmg * atk;
    ttl_damage +=
        base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
}

void charge_atk_oz_for_thunder() {
    if (!charging) return;
    if (oz_timer <= 0) return;
    if (full_charge_timer > 0) return;
    charging           = false;
    double base_damage = enemy_count * atk * oz_thunder_ratio;
    ttl_damage +=
        base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
    thunder_dmg +=
        base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
    thunder_count += 1;
}

void init_oz() { oz_timer = oz_time + skill_1_cast_time; }

void action() {
    if (skill_black_out_timer > 0) return;
    if (charge_atk_oz and oz_timer <= oz_time and
        oz_timer > full_charge_time and !charging) {
        skill_black_out_timer = full_charge_time;
        full_charge_timer     = full_charge_time;
        charging              = true;
        return;
    }
    //// if normal attack
    if (combo_CD_timer <= 0) {
        normal_attack();
        combo_CD_timer = combo_cooldown[combo_count];
        normal_attack_counter[combo_count]++;
        combo_count = (++combo_count) % combo_ttl;
    }
    if (skill_1_CD_timer <= 0 and combo_count < skill_1_combo_lower_bound) {
        skill_1();
        skill_1_counter++;
        combo_count    = 0;
        combo_CD_timer = 0;
        init_oz();
        skill_black_out_timer = skill_1_cast_time;
        skill_1_CD_timer      = skill_1_cooldown + skill_1_cast_time;
    }
}

void oz() {
    if (oz_timer > oz_time) return;
    if (oz_timer <= 0) return;
    if (oz_atk_timer <= 0) {
        double base_damage = atk * oz_atk_ratio;
        oz_atk_count++;
        oz_atk_timer = oz_atk_cooldown;
        ttl_damage +=
            base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
        ttl_oz_damage +=
            base_damage * (1 - crit_rate) + base_damage * crit_dmg * crit_rate;
    }
}

////// Controllers
void timer() {
    combo_CD_timer -= STEP_TIME;
    skill_black_out_timer -= STEP_TIME;
    skill_1_CD_timer -= STEP_TIME;
    oz_timer -= STEP_TIME;
    oz_atk_timer -= STEP_TIME;
    full_charge_timer -= STEP_TIME;
}

int main() {
    crit_dmg += 1;
    normal_attack_bonus += 1;
    for (double t = 0; t < SIM_LENGTH; t += STEP_TIME) {
        timer();
        action();
        oz();
        charge_atk_oz_for_thunder();
    }
    cout << "Skill One was casted " << skill_1_counter << " times." << endl;
    for (int i = 0; i < combo_ttl; i++) {
        cout << "Combo " << i + 1 << " hit " << normal_attack_counter[i]
             << " times." << endl;
    }
    cout << "Total Damage: " << ttl_damage << endl;
    cout << "Total OZ Damage: " << ttl_oz_damage
         << " atk count: " << oz_atk_count << endl;
    cout << "Thunder dmg: " << thunder_dmg
         << " Thunder count: " << thunder_count << endl;
}

