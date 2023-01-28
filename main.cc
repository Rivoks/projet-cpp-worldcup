#include <iostream>
#include <vector>
#include <future>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"
#include "Classes/Action/Action.hh"
#include "Classes/Team/Team.hh"
#include "Classes/Match/Match.hh"
#include "Classes/Tournament/Tournament.hh"
#define TIME 20 // Define a match duration

Team _chooseTeam(int n) 
{
    if (n == 0) 
    {
        PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
        PlayerATK bruno("Bruno Fernandes", 8, 72, 86, 81);
        PlayerDEF ruben("Ruben Dias", 3, 73, 88, 88);
        PlayerDEF cancelo("Cancelo", 20, 85, 81, 73);
        PlayerGK patricio("Rui Patricio", 1, 79, 86);

        vector<PlayerATK> atk{ronaldo, bruno};
        vector<PlayerDEF> def{ruben, cancelo};

        Team team(atk, def, patricio, "Portugal");

        return team;
    }

    if (n == 1) 
    {
        PlayerATK neymar("Neymar", 10, 87, 83, 93);
        PlayerATK vinicius("Vinicius", 20, 95, 79, 90);
        PlayerDEF thiago("Thiago Silva", 3, 79, 87, 76);
        PlayerDEF marquinhos("Marquinhos", 5, 79, 89, 80);
        PlayerGK alisson("Alisson", 1, 80, 86);

        vector<PlayerATK> atk{neymar, vinicius};
        vector<PlayerDEF> def{thiago, marquinhos};

        Team team(atk, def, alisson, "Brésil");

        return team;
    }
    
    if (n == 2) 
    {
        PlayerATK mbappe("Mbappe", 10, 97, 89, 92);
        PlayerATK payet("Payet", 10, 99, 99, 99);
        PlayerDEF varane("Varane", 4, 81, 85, 80);
        PlayerDEF saliba("Saliba", 3, 78, 80, 79);
        PlayerGK lloris("Lloris", 1, 71, 88);

        vector<PlayerATK> atk{mbappe, payet};
        vector<PlayerDEF> def{varane, saliba};

        Team team(atk, def, lloris, "France");

        return team;
    }       

    if (n==3)
    {
        PlayerATK pessi("Pessi", 10, 81, 89, 94);
        PlayerATK dimaria("Di Maria", 11, 79, 79, 87);
        PlayerDEF otamendi("Otamendi", 19, 73, 83, 81);
        PlayerDEF martinez("Lisandro Martinez", 25, 76, 82, 83);
        PlayerGK partinez("Pemiliano Partinez", 1, 68, 85);

        vector<PlayerATK> atk{pessi, dimaria};
        vector<PlayerDEF> def{otamendi, martinez};

        Team team(atk, def, partinez, "Argentine");

        return team;

    }

    else 
    {
        PlayerATK ziyech("Ziyech", 7, 76, 77, 83);
        PlayerATK harit("Harit", 10, 86, 80, 88);
        PlayerDEF hakimi("Hakimi", 2, 92, 75, 78);
        PlayerDEF aguerd("Aguerd", 4, 73, 80, 77);
        PlayerGK bounou("Bounou", 13, 84, 76);
        vector<PlayerATK> atk{ziyech, harit};
        vector<PlayerDEF> def{hakimi, aguerd};
        Team team(atk, def, bounou, "Maroc");

        return team;
    }
}

vector<Team> _initTeamList() {

    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerATK bruno("Bruno Fernandes", 8, 72, 86, 81);
    PlayerDEF ruben("Ruben Dias", 3, 73, 88, 88);
    PlayerDEF cancelo("Cancelo", 20, 85, 81, 73);
    PlayerGK patricio("Rui Patricio", 1, 79, 86);
    vector<PlayerATK> atk0{ronaldo, bruno};
    vector<PlayerDEF> def0{ruben, cancelo};
    Team team0(atk0, def0, patricio, "Portugal");

    PlayerATK neymar("Neymar", 10, 87, 83, 93);
    PlayerATK vinicius("Vinicius", 20, 95, 79, 90);
    PlayerDEF thiago("Thiago Silva", 3, 79, 87, 76);
    PlayerDEF marquinhos("Marquinhos", 5, 79, 89, 80);
    PlayerGK alisson("Alisson", 1, 80, 86);
    vector<PlayerATK> atk1{neymar, vinicius};
    vector<PlayerDEF> def1{thiago, marquinhos};
    Team team1(atk1, def1, alisson, "Brésil");

    PlayerATK mbappe("Mbappe", 10, 97, 89, 92);
    PlayerATK payet("Payet", 10, 99, 99, 99);
    PlayerDEF varane("Varane", 4, 81, 85, 80);
    PlayerDEF saliba("Saliba", 3, 78, 80, 79);
    PlayerGK lloris("Lloris", 1, 71, 88);
    vector<PlayerATK> atk2{mbappe, payet};
    vector<PlayerDEF> def2{varane, saliba};
    Team team2(atk2, def2, lloris, "France");

    PlayerATK pessi("Pessi", 10, 81, 89, 94);
    PlayerATK dimaria("Di Maria", 11, 79, 79, 87);
    PlayerDEF otamendi("Otamendi", 19, 73, 83, 81);
    PlayerDEF martinez("Lisandro Martinez", 25, 76, 82, 83);
    PlayerGK partinez("Pemiliano Partinez", 1, 68, 85);
    vector<PlayerATK> atk3{pessi, dimaria};
    vector<PlayerDEF> def3{otamendi, martinez};
    Team team3(atk3, def3, partinez, "Argentine");

    PlayerATK ziyech("Ziyech", 7, 76, 77, 83);
    PlayerATK harit("Harit", 10, 86, 80, 88);
    PlayerDEF hakimi("Hakimi", 2, 92, 75, 78);
    PlayerDEF aguerd("Aguerd", 4, 73, 80, 77);
    PlayerGK bounou("Bounou", 13, 84, 76);
    vector<PlayerATK> atk4{ziyech, harit};
    vector<PlayerDEF> def4{hakimi, aguerd};
    Team team4(atk4, def4, bounou, "Maroc");

    vector<Team> teams{team0, team1, team2, team3, team4};
    return teams;

}

void _initTournament() // This function leads our tournament
{
    int teamChoice; // We have to choose which team we are going to play
    cout << "Ouverture du grand tournoi : Coupe du monde 2022" << endl;
    cout << "Select your team : \n (0) Portugal \n (1) Brésil \n (2) France \n (3) Argentine \n (4) Maroc" << endl;
    cin >> teamChoice;
    Team myTeam = _chooseTeam(teamChoice);
    myTeam._printPlayers(); // We print the playes of our team
    vector<Team> teams = _initTeamList(); // We store all the teams of the Cup in this vector

    Tournament CDM22(teams, teamChoice); // Creation of our tournament WC22
    
    int i = 0;
    while (CDM22._getTournamentStatus() && i < teams.size()) { // While our team does not lose and it stills teams in the tournament

        if (i != teamChoice ) // We play against all the team except ours
        {
            vector<Team> teamTmp{myTeam, teams[i]}; // Temporary vector to store the two teams of the current match
            Match match(teamTmp, TIME);
            cout << "le " << i+1 << "e" << " match opposera " << teamTmp[0]._getName() << " à " << teamTmp[1]._getName() << " GOOOOO " << endl;
            auto f = std::async(&Match::startMatch, &match);
            if (not(match._runMatch())) CDM22._updateTournamentStatus(); // If we lose, the tournament is over
        }
        i++;
    }
    
    if (CDM22._getTournamentStatus()) cout << "LE VAINQUEUR DE LA COUPE DU MONDE 2022 EST " << myTeam._getName() << endl;

    else cout << "LE VAINQUEUR DE LA COUPE DU MONDE 2022 EST " << teams[i - 1]._getName() << endl << "Quelle DÉSILLUSION pour " << myTeam._getName();

    cout << endl << "ALLEZ L'OM !!!!" << endl;
}

int main()
{
    _initTournament();

    return 0;
}