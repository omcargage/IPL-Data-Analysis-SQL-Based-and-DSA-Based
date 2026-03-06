#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
using namespace std;

const int MAX_NAME_LENGTH = 100;
const int MAX_DATE_LENGTH = 20;
const int MAX_TEXT_LENGTH = 1000;

struct BattingCard {
    int season;
    char match_name[MAX_NAME_LENGTH];
    char fullName[MAX_NAME_LENGTH];
    int runs;
    float strikeRate;
    int fours;
    int sixes;  
    char home_team[MAX_NAME_LENGTH];
    char away_team[MAX_NAME_LENGTH];    
};

struct BowlingCard {
    int season;
    char match_name[MAX_NAME_LENGTH];
    char home_team[MAX_NAME_LENGTH];
    char away_team[MAX_NAME_LENGTH];
    char bowling_team[MAX_NAME_LENGTH];
    char venue[MAX_NAME_LENGTH];
    char fullName[MAX_NAME_LENGTH];
    float overs;
    int maidens;
    int conceded;
    int wickets;
    float economyRate;
    int dots;
    int foursConceded;
    int sixesConceded;
    int wides;
    int noballs;
};

// Structure to hold ball-by-ball data
struct BallByBallData {
    int season;
    char match_name[MAX_NAME_LENGTH];
    char home_team[MAX_NAME_LENGTH];
    char away_team[MAX_NAME_LENGTH];
    char current_innings[MAX_NAME_LENGTH];
    int innings_id;
    int over;
    int ball;
    int runs;
    
    // Primary batting pair
    char batsman1_name[MAX_NAME_LENGTH];
    int batsman1_runs;
    int batsman1_balls;
    
    // Primary bowler
    char bowler1_name[MAX_NAME_LENGTH];
    float bowler1_overs;
    int bowler1_maidens;
    int bowler1_runs;
    int bowler1_wkts;
    
    // Secondary batting pair
    char batsman2_name[MAX_NAME_LENGTH];
    int batsman2_runs;
    int batsman2_balls;
    
    // Secondary bowler
    char bowler2_name[MAX_NAME_LENGTH];
    float bowler2_overs;
    int bowler2_maidens;
    int bowler2_runs;
    int bowler2_wkts;
    
    // Wicket details (if any)
    char wkt_batsman_name[MAX_NAME_LENGTH];
    char wkt_bowler_name[MAX_NAME_LENGTH];
    int wkt_batsman_runs;
    int wkt_batsman_balls;
};

// Structure to hold season-wise bowling stats
struct SeasonBowlingStats {
    char fullName[MAX_NAME_LENGTH];
    int season;
    float totalOvers;
    int totalMaidens;
    int totalRuns;
    int totalWickets;
    int totalDots;
    float economyRate;
    int matches;
};

// Structure to hold season-wise batting stats
struct SeasonBattingStats {
    char fullName[MAX_NAME_LENGTH];
    int season;
    int totalRuns;
    int totalSixes;
    int totalFours;
    int matches;
    float avgStrikeRate;
};

struct Partnership {
    char batsman1[MAX_NAME_LENGTH];
    char batsman2[MAX_NAME_LENGTH];
    int totalRuns;
    string match_name;
    int season;
};

struct DeathOverStats {
    char bowlerName[MAX_NAME_LENGTH];
    int totalRuns;
    int totalBalls;
    int wickets;
    float economyRate;
    int matches;
};

struct MatchSummary {
    int season;
    char name[MAX_NAME_LENGTH];
    char short_name[MAX_NAME_LENGTH];
    char home_team[MAX_NAME_LENGTH];
    char away_team[MAX_NAME_LENGTH];
    char toss_won[MAX_NAME_LENGTH];
    char decision[MAX_NAME_LENGTH];
    int first_innings_score;
    int second_innings_score;
    int home_score;
    int away_score;
    char winner[MAX_NAME_LENGTH];
    char venue_name[MAX_NAME_LENGTH];
    float home_overs;
    int home_runs;
    int home_wickets;
    int home_boundaries;
    float away_overs;
    int away_runs;
    int away_wickets;
    int away_boundaries;
};

struct TeamSeasonStats {
    char teamName[MAX_NAME_LENGTH];
    char captain[MAX_NAME_LENGTH];
    int wins;
    int matches;
    float winPercentage;
};

struct TeamScoreStats {
    char teamName[MAX_NAME_LENGTH];
    int totalRuns;
    int matches;
    float averageScore;
    int highestScore;
    char highestScoreMatch[MAX_NAME_LENGTH];
};

vector<string> splitLine(const string &line)
{
    vector<string> values;
    string value;
    bool inQuotes = false;
    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (c == '\"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            values.push_back(value);
            value.clear();
        } else {
            value += c;
        }
    }
    values.push_back(value);
    return values;
}

void showLoadingIndicator(const string& message) {
    const char spinner[] = {'|', '/', '-', '\\'};
    int i = 0;
    cout << message;
    for(int j = 0; j < 3; j++) {
        cout << spinner[i] << '\b';
        this_thread::sleep_for(chrono::milliseconds(300));
        i = (i + 1) % 4;
    }
    cout << " Done!" << endl;
}

int getValidInput(int min, int max) {
    int choice;
    while(true) {
        if(cin >> choice) {
            if(choice >= min && choice <= max) {
                cin.ignore(10000, '\n');
                return choice;
            }
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
    }
}

float getValidFloat(float min, float max, const string& prompt) {
    float value;
    while(true) {
        cout << prompt;
        if(cin >> value) {
            if(value >= min && value <= max) {
                cin.ignore(10000, '\n');
                return value;
            }
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << endl;
    }
}

void printMenuHeader(const string& title) {
    cout << "\n================================================\n";
    cout << "               IPL DATA ANALYSIS                 \n";
    cout << "================================================\n";
    cout << "              " << title << "                    \n";
    cout << "================================================\n";
}

vector<BattingCard> battingdata(const string &filename)
{
    ifstream file(filename);
    vector<BattingCard> battingdata;

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file. Please check the file path and try again.\n";
        return battingdata;
    }

    std::cout << "File opened successfully!\n";

    string line;
    getline(file, line); // Skip header row

    while (getline(file, line))
    {
        vector<string> values = splitLine(line);
        if (values.size() >= 5)
        {
            try
            {
                BattingCard battingcard;
                battingcard.season = stoi(values[0]);
                strcpy(battingcard.match_name, values[1].c_str());
                strcpy(battingcard.fullName, values[2].c_str());
                battingcard.runs = stoi(values[3]);
                battingcard.fours = stoi(values[4]);
                battingcard.sixes = stoi(values[5]);
                battingcard.strikeRate = stof(values[6]);
                strcpy(battingcard.home_team, values[7].c_str());
                strcpy(battingcard.away_team, values[8].c_str());
                battingdata.push_back(battingcard);
            }
            catch (const exception &e)
            {
                std::cout << "Skipping invalid row: " << line << "\n";
                continue;
            }
        }
        else
        {
            std::cout << "Skipping row with insufficient columns: " << line << "\n";
        }
    }

    file.close();
    std::cout<<"Batting Data loaded successfully! Total cards: " << battingdata.size() << "\n";

    return battingdata;
}

vector<BowlingCard> bowlingdata(const string &filename)
{
    ifstream file(filename);
    vector<BowlingCard> bowlingdata;

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file. Please check the file path and try again.\n";
        return bowlingdata;
    }

    std::cout << "File opened successfully!\n";

    string line;
    getline(file, line); // Skip header row

    while (getline(file, line))
    {
        vector<string> values = splitLine(line);
        if (values.size() >= 10)
        {
            try
            {
                BowlingCard bowlingcard;
                bowlingcard.season = values[0].empty() ? 0 : stoi(values[0]);
                strcpy(bowlingcard.match_name, values[1].c_str());
                strcpy(bowlingcard.home_team, values[2].c_str());
                strcpy(bowlingcard.away_team, values[3].c_str());
                strcpy(bowlingcard.bowling_team, values[4].c_str());
                strcpy(bowlingcard.venue, values[5].c_str());
                strcpy(bowlingcard.fullName, values[6].c_str());
                bowlingcard.overs = values[7].empty() ? 0.0f : stof(values[7]);
                bowlingcard.maidens = values[8].empty() ? 0 : stoi(values[8]);
                bowlingcard.conceded = values[9].empty() ? 0 : stoi(values[9]);
                bowlingcard.wickets = values[10].empty() ? 0 : stoi(values[10]);
                bowlingcard.economyRate = values[11].empty() ? 0.0f : stof(values[11]);
                bowlingcard.dots = values[12].empty() ? 0 : stoi(values[12]);
                bowlingcard.foursConceded = values[13].empty() ? 0 : stoi(values[13]);
                bowlingcard.sixesConceded = values[14].empty() ? 0 : stoi(values[14]);
                bowlingcard.wides = values[15].empty() ? 0 : stoi(values[15]);
                bowlingcard.noballs = values[16].empty() ? 0 : stoi(values[16]);
                bowlingdata.push_back(bowlingcard);
            }
            catch (const exception &e)
            {
                std::cout << "Skipping invalid row: " << line << "\n";
                continue;
            }
        }
        else
        {
            std::cout << "Skipping row with insufficient columns: " << line << "\n";
        }
    }

    file.close();
    std::cout << "Bowling Data loaded successfully! Total cards: " << bowlingdata.size() << "\n";

    return bowlingdata;
}

// Function to read ball-by-ball data from CSV with minimal line skipping
vector<BallByBallData> readBallByBallData(const string& filename) {
    ifstream file(filename);
    vector<BallByBallData> ballData;

    if (!file.is_open()) {
        cerr << "Error: Unable to open ball-by-ball data file.\n";
        return ballData;
    }

    string line;
    getline(file, line); // Skip header row

    int lineNumber = 1; // Track line numbers for better error reporting
    while (getline(file, line)) {
        lineNumber++;
        vector<string> values = splitLine(line);
        
        // Check if we have minimum required columns
        if (values.size() < 29) { // We expect at least 29 columns
            cerr << "Warning: Line " << lineNumber << " has insufficient columns (" << values.size() << "). Expected 29.\n";
            continue;
        }

        try {
            BallByBallData ball;
            
            // Basic game information
            ball.season = values[0].empty() ? 0 : stoi(values[0]);
            strncpy(ball.match_name, values[1].c_str(), MAX_NAME_LENGTH - 1);
            strncpy(ball.home_team, values[2].c_str(), MAX_NAME_LENGTH - 1);
            strncpy(ball.away_team, values[3].c_str(), MAX_NAME_LENGTH - 1);
            strncpy(ball.current_innings, values[4].c_str(), MAX_NAME_LENGTH - 1);
            
            // Game state information
            ball.innings_id = values[5].empty() ? 0 : stoi(values[5]);
            ball.over = values[6].empty() ? 0 : stoi(values[6]);
            ball.ball = values[7].empty() ? 0 : stoi(values[7]);
            ball.runs = values[8].empty() ? 0 : stoi(values[8]);
            
            // Batsman 1 information
            strncpy(ball.batsman1_name, values[9].c_str(), MAX_NAME_LENGTH - 1);
            ball.batsman1_runs = values[10].empty() ? 0 : stoi(values[10]);
            ball.batsman1_balls = values[11].empty() ? 0 : stoi(values[11]);
            
            // Bowler 1 information
            strncpy(ball.bowler1_name, values[12].c_str(), MAX_NAME_LENGTH - 1);
            ball.bowler1_overs = values[13].empty() ? 0.0f : stof(values[13]);
            ball.bowler1_maidens = values[14].empty() ? 0 : stoi(values[14]);
            ball.bowler1_runs = values[15].empty() ? 0 : stoi(values[15]);
            ball.bowler1_wkts = values[16].empty() ? 0 : stoi(values[16]);
            
            // Batsman 2 information
            strncpy(ball.batsman2_name, values[17].c_str(), MAX_NAME_LENGTH - 1);
            ball.batsman2_runs = values[18].empty() ? 0 : stoi(values[18]);
            ball.batsman2_balls = values[19].empty() ? 0 : stoi(values[19]);
            
            // Bowler 2 information
            strncpy(ball.bowler2_name, values[20].c_str(), MAX_NAME_LENGTH - 1);
            ball.bowler2_overs = values[21].empty() ? 0.0f : stof(values[21]);
            ball.bowler2_maidens = values[22].empty() ? 0 : stoi(values[22]);
            ball.bowler2_runs = values[23].empty() ? 0 : stoi(values[23]);
            ball.bowler2_wkts = values[24].empty() ? 0 : stoi(values[24]);
            
            // Wicket information
            strncpy(ball.wkt_batsman_name, values[25].c_str(), MAX_NAME_LENGTH - 1);
            strncpy(ball.wkt_bowler_name, values[26].c_str(), MAX_NAME_LENGTH - 1);
            ball.wkt_batsman_runs = values[27].empty() ? 0 : stoi(values[27]);
            ball.wkt_batsman_balls = values[28].empty() ? 0 : stoi(values[28]);
            
            // Add null terminators for all strings
            ball.match_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.home_team[MAX_NAME_LENGTH - 1] = '\0';
            ball.away_team[MAX_NAME_LENGTH - 1] = '\0';
            ball.current_innings[MAX_NAME_LENGTH - 1] = '\0';
            ball.batsman1_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.bowler1_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.batsman2_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.bowler2_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.wkt_batsman_name[MAX_NAME_LENGTH - 1] = '\0';
            ball.wkt_bowler_name[MAX_NAME_LENGTH - 1] = '\0';
            
            ballData.push_back(ball);
        }
        catch (const exception& e) {
            cerr << "Warning: Error processing line " << lineNumber << ": " << e.what() << "\n";
            cerr << "Line content: " << line << "\n";
            // Continue to next line instead of skipping
        }
    }

    file.close();
    cout << "Ball by ball data loaded successfully! Total deliveries: " << ballData.size() << "\n";
    if (ballData.size() > 0) {
        cout << "All files successfully loaded!" << "\n";
    }
    return ballData;
}

vector<MatchSummary> readMatchSummaryData(const string& filename) {
    ifstream file(filename);
    vector<MatchSummary> summaryData;

    if (!file.is_open()) {
        cerr << "Error: Unable to open match summary file. Please check the file path and try again.\n";
        return summaryData;
    }

    cout << "Match Summary file opened successfully!\n";

    string line;
    getline(file, line); // Skip header row
    int lineNumber = 1;
    int skippedRows = 0;

    while (getline(file, line)) {
        lineNumber++;
        vector<string> values = splitLine(line);
        
        try {
            MatchSummary summary;
            
            // Basic match information
            summary.season = values.size() > 0 && !values[0].empty() ? stoi(values[0]) : 0;
            strncpy(summary.name, values.size() > 1 ? values[1].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.short_name, values.size() > 2 ? values[2].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.home_team, values.size() > 3 ? values[3].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.away_team, values.size() > 4 ? values[4].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.toss_won, values.size() > 5 ? values[5].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.decision, values.size() > 6 ? values[6].c_str() : "", MAX_NAME_LENGTH - 1);
            
            // Score information
            summary.first_innings_score = values.size() > 7 && !values[7].empty() ? stoi(values[7]) : 0;
            summary.second_innings_score = values.size() > 8 && !values[8].empty() ? stoi(values[8]) : 0;
            summary.home_score = values.size() > 9 && !values[9].empty() ? stoi(values[9]) : 0;
            summary.away_score = values.size() > 10 && !values[10].empty() ? stoi(values[10]) : 0;
            
            // Match result and venue
            strncpy(summary.winner, values.size() > 11 ? values[11].c_str() : "", MAX_NAME_LENGTH - 1);
            strncpy(summary.venue_name, values.size() > 12 ? values[12].c_str() : "", MAX_NAME_LENGTH - 1);
            
            // Detailed statistics
            summary.home_overs = values.size() > 13 && !values[13].empty() ? stof(values[13]) : 0.0f;
            summary.home_runs = values.size() > 14 && !values[14].empty() ? stoi(values[14]) : 0;
            summary.home_wickets = values.size() > 15 && !values[15].empty() ? stoi(values[15]) : 0;
            summary.home_boundaries = values.size() > 16 && !values[16].empty() ? stoi(values[16]) : 0;
            summary.away_overs = values.size() > 17 && !values[17].empty() ? stof(values[17]) : 0.0f;
            summary.away_runs = values.size() > 18 && !values[18].empty() ? stoi(values[18]) : 0;
            summary.away_wickets = values.size() > 19 && !values[19].empty() ? stoi(values[19]) : 0;
            summary.away_boundaries = values.size() > 20 && !values[20].empty() ? stoi(values[20]) : 0;

            // Ensure null termination for all strings
            summary.name[MAX_NAME_LENGTH - 1] = '\0';
            summary.short_name[MAX_NAME_LENGTH - 1] = '\0';
            summary.home_team[MAX_NAME_LENGTH - 1] = '\0';
            summary.away_team[MAX_NAME_LENGTH - 1] = '\0';
            summary.toss_won[MAX_NAME_LENGTH - 1] = '\0';
            summary.decision[MAX_NAME_LENGTH - 1] = '\0';
            summary.winner[MAX_NAME_LENGTH - 1] = '\0';
            summary.venue_name[MAX_NAME_LENGTH - 1] = '\0';

            // Only skip if we're missing critical match information
            if (summary.season == 0 || strlen(summary.home_team) == 0 || strlen(summary.away_team) == 0) {
                cout << "Warning: Skipping row " << lineNumber << " due to missing critical data\n";
                skippedRows++;
                continue;
            }

            summaryData.push_back(summary);
        }
        catch (const exception& e) {
            cout << "Warning: Error processing row " << lineNumber << ": " << e.what() << "\n";
            cout << "Line content: " << line << "\n";
            skippedRows++;
        }
    }

    file.close();
    cout << "Match Summary Data loaded successfully!\n";
    cout << "Total matches loaded: " << summaryData.size() << "\n";
    cout << "Skipped rows: " << skippedRows << "\n";

    return summaryData;
}

// Helper function for QuickSort - partition
int partitionBattingCards(vector<BattingCard>& arr, int low, int high) {
    BattingCard pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j].runs > pivot.runs) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort implementation for BattingCards
void quickSortBattingCards(vector<BattingCard>& arr, int low, int high) {
    if(low < high) {
        int pi = partitionBattingCards(arr, low, high);
        quickSortBattingCards(arr, low, pi - 1);
        quickSortBattingCards(arr, pi + 1, high);
    }
}

// Helper function for QuickSort - partition by sixes
int partitionBattingCardsBySixes(vector<BattingCard>& arr, int low, int high) {
    BattingCard pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j].sixes > pivot.sixes) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort implementation for BattingCards by sixes
void quickSortBattingCardsBySixes(vector<BattingCard>& arr, int low, int high) {
    if(low < high) {
        int pi = partitionBattingCardsBySixes(arr, low, high);
        quickSortBattingCardsBySixes(arr, low, pi - 1);
        quickSortBattingCardsBySixes(arr, pi + 1, high);
    }
}

// Helper function for QuickSort - partition by fours
int partitionBattingCardsByFours(vector<BattingCard>& arr, int low, int high) {
    BattingCard pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j].fours > pivot.fours) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort implementation for BattingCards by fours
void quickSortBattingCardsByFours(vector<BattingCard>& arr, int low, int high) {
    if(low < high) {
        int pi = partitionBattingCardsByFours(arr, low, high);
        quickSortBattingCardsByFours(arr, low, pi - 1);
        quickSortBattingCardsByFours(arr, pi + 1, high);
    }
}

// Helper function to merge two sorted subarrays for strike rate sorting
void mergeBattingCardsByStrikeRate(vector<BattingCard>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    vector<BattingCard> L(n1), R(n2);
    
    // Copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i].strikeRate >= R[j].strikeRate) {  // Using >= for descending order
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[] if any
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[] if any
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort implementation for BattingCards by strike rate
void mergeSortBattingCardsByStrikeRate(vector<BattingCard>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSortBattingCardsByStrikeRate(arr, left, mid);
        mergeSortBattingCardsByStrikeRate(arr, mid + 1, right);
        mergeBattingCardsByStrikeRate(arr, left, mid, right);
    }
}

// Helper function for QuickSort - partition by economy rate
int partitionBowlingByEconomy(vector<BowlingCard>& arr, int low, int high) {
    BowlingCard pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j].economyRate < pivot.economyRate) {  // Lower economy is better
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort for bowling cards by economy rate
void quickSortBowlingByEconomy(vector<BowlingCard>& arr, int low, int high) {
    if(low < high) {
        int pi = partitionBowlingByEconomy(arr, low, high);
        quickSortBowlingByEconomy(arr, low, pi - 1);
        quickSortBowlingByEconomy(arr, pi + 1, high);
    }
}

// Helper function for QuickSort - partition by wickets
int partitionBowlingByWickets(vector<BowlingCard>& arr, int low, int high) {
    BowlingCard pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j].wickets > pivot.wickets) {  // More wickets is better
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort for bowling cards by wickets
void quickSortBowlingByWickets(vector<BowlingCard>& arr, int low, int high) {
    if(low < high) {
        int pi = partitionBowlingByWickets(arr, low, high);
        quickSortBowlingByWickets(arr, low, pi - 1);
        quickSortBowlingByWickets(arr, pi + 1, high);
    }
}

// Helper function to calculate season-wise bowling statistics
vector<SeasonBowlingStats> calculateSeasonStats(const vector<BowlingCard>& data) {
    // Map to store bowler stats by season (name+season is key)
    map<pair<string, int>, SeasonBowlingStats> statsMap;
    
    for(const auto& card : data) {
        string name = card.fullName;
        pair<string, int> key = make_pair(name, card.season);
        
        if(statsMap.find(key) == statsMap.end()) {
            SeasonBowlingStats stats;
            strcpy(stats.fullName, card.fullName);
            stats.season = card.season;
            stats.totalOvers = 0;
            stats.totalMaidens = 0;
            stats.totalRuns = 0;
            stats.totalWickets = 0;
            stats.totalDots = 0;
            stats.matches = 0;
            statsMap[key] = stats;
        }
        
        auto& stats = statsMap[key];
        stats.totalOvers += card.overs;
        stats.totalMaidens += card.maidens;
        stats.totalRuns += card.conceded;
        stats.totalWickets += card.wickets;
        stats.totalDots += card.dots;
        stats.matches++;
    }
    
    // Convert map to vector
    vector<SeasonBowlingStats> result;
    for(const auto& pair : statsMap) {
        SeasonBowlingStats stats = pair.second;
        // Calculate economy rate for the season
        stats.economyRate = stats.totalRuns / (stats.totalOvers);
        result.push_back(stats);
    }
    
    return result;
}

// Helper function to calculate season batting statistics
vector<SeasonBattingStats> calculateSeasonBattingStats(const vector<BattingCard>& data, int targetSeason) {
    map<string, SeasonBattingStats> statsMap;
    
    for(const auto& card : data) {
        if(card.season == targetSeason) {
            string name = card.fullName;
            
            if(statsMap.find(name) == statsMap.end()) {
                SeasonBattingStats stats;
                strcpy(stats.fullName, card.fullName);
                stats.season = targetSeason;
                stats.totalRuns = 0;
                stats.totalSixes = 0;
                stats.totalFours = 0;
                stats.matches = 0;
                stats.avgStrikeRate = 0;
                statsMap[name] = stats;
            }
            
            auto& stats = statsMap[name];
            stats.totalRuns += card.runs;
            stats.totalSixes += card.sixes;
            stats.totalFours += card.fours;
            stats.avgStrikeRate += card.strikeRate;
            stats.matches++;
        }
    }
    
    // Convert map to vector and calculate averages
    vector<SeasonBattingStats> result;
    for(const auto& pair : statsMap) {
        SeasonBattingStats stats = pair.second;
        stats.avgStrikeRate /= stats.matches;  // Calculate average strike rate
        result.push_back(stats);
    }
    
    return result;
}

// Print dot ball specialists
void printDotBallSpecialists(const vector<BowlingCard>& data, float minOvers = 2.0, int topN = 10) {
    vector<BowlingCard> sorted = data;
    
    // Sort by dot ball percentage
    sort(sorted.begin(), sorted.end(), 
        [](const BowlingCard& a, const BowlingCard& b) {
            float a_dot_percent = (a.dots / (a.overs * 6.0f)) * 100;
            float b_dot_percent = (b.dots / (a.overs * 6.0f)) * 100;
            return a_dot_percent > b_dot_percent;
        });

    cout << "\nTop " << topN << " Dot Ball Specialists (min " << minOvers << " overs):\n";
    cout << string(85, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(15) << "Dot Ball %"
         << setw(10) << "Dots"
         << setw(10) << "Overs"
         << setw(12) << "Economy"
         << "Match" << endl;
    cout << string(85, '-') << endl;

    int count = 0;
    for(const auto& card : sorted) {
        if(card.overs >= minOvers) {
            float dot_percentage = (card.dots / (card.overs * 6.0f)) * 100;
            cout << left << setw(25) << card.fullName
                 << setw(15) << fixed << setprecision(2) << dot_percentage
                 << setw(10) << card.dots
                 << setw(10) << card.overs
                 << setw(12) << card.economyRate
                 << card.match_name << endl;
            count++;
            if(count >= topN) break;
        }
    }
    cout << string(85, '-') << endl;
}

// Print maiden over specialists
void printMaidenSpecialists(const vector<BowlingCard>& data, float minOvers = 2.0, int topN = 10) {
    vector<BowlingCard> sorted = data;
    
    // Sort by maiden over percentage
    sort(sorted.begin(), sorted.end(), 
        [](const BowlingCard& a, const BowlingCard& b) {
            float a_maiden_percent = (a.maidens / a.overs) * 100;
            float b_maiden_percent = (b.maidens / a.overs) * 100;
            return a_maiden_percent > b_maiden_percent;
        });

    cout << "\nTop " << topN << " Maiden Over Specialists (min " << minOvers << " overs):\n";
    cout << string(85, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(15) << "Maiden %"
         << setw(10) << "Maidens"
         << setw(10) << "Overs"
         << setw(12) << "Economy"
         << "Match" << endl;
    cout << string(85, '-') << endl;

    int count = 0;
    for(const auto& card : sorted) {
        if(card.overs >= minOvers) {
            float maiden_percentage = (card.maidens / card.overs) * 100;
            cout << left << setw(25) << card.fullName
                 << setw(15) << fixed << setprecision(2) << maiden_percentage
                 << setw(10) << card.maidens
                 << setw(10) << card.overs
                 << setw(12) << card.economyRate
                 << card.match_name << endl;
            count++;
            if(count >= topN) break;
        }
    }
    cout << string(85, '-') << endl;
}

// Print season-wise economical bowlers
void printSeasonEconomicalBowlers(const vector<BowlingCard>& data, int targetSeason, float minOvers = 20.0, int topN = 10) {
    vector<SeasonBowlingStats> seasonStats = calculateSeasonStats(data);
    
    // Filter for target season and sort by economy rate
    vector<SeasonBowlingStats> sorted;
    for(const auto& stats : seasonStats) {
        if(stats.season == targetSeason && stats.totalOvers >= minOvers) {
            sorted.push_back(stats);
        }
    }
    
    sort(sorted.begin(), sorted.end(), 
        [](const SeasonBowlingStats& a, const SeasonBowlingStats& b) {
            return a.economyRate < b.economyRate;
        });

    cout << "\nTop " << topN << " Economical Bowlers for Season " << targetSeason 
         << " (min " << minOvers << " overs):\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(12) << "Economy" 
         << setw(10) << "Overs"
         << setw(10) << "Runs"
         << setw(10) << "Wickets"
         << setw(10) << "Matches"
         << "Maidens" << endl;
    cout << string(100, '-') << endl;

    for(int i = 0; i < min(topN, (int)sorted.size()); i++) {
        cout << left << setw(25) << sorted[i].fullName
             << setw(12) << fixed << setprecision(2) << sorted[i].economyRate
             << setw(10) << sorted[i].totalOvers
             << setw(10) << sorted[i].totalRuns
             << setw(10) << sorted[i].totalWickets
             << setw(10) << sorted[i].matches
             << sorted[i].totalMaidens << endl;
    }
    cout << string(100, '-') << endl;
}

// Print season-wise wicket takers
void printSeasonWicketTakers(const vector<BowlingCard>& data, int targetSeason, float minOvers = 20.0, int topN = 10) {
    vector<SeasonBowlingStats> seasonStats = calculateSeasonStats(data);
    
    // Filter for target season and sort by wickets
    vector<SeasonBowlingStats> sorted;
    for(const auto& stats : seasonStats) {
        if(stats.season == targetSeason && stats.totalOvers >= minOvers) {
            sorted.push_back(stats);
        }
    }
    
    sort(sorted.begin(), sorted.end(), 
        [](const SeasonBowlingStats& a, const SeasonBowlingStats& b) {
            return a.totalWickets > b.totalWickets;
        });

    cout << "\nTop " << topN << " Wicket Takers for Season " << targetSeason 
         << " (min " << minOvers << " overs):\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(10) << "Wickets"
         << setw(12) << "Economy" 
         << setw(10) << "Overs"
         << setw(10) << "Matches"
         << "Avg" << endl;
    cout << string(100, '-') << endl;

    for(int i = 0; i < min(topN, (int)sorted.size()); i++) {
        float average = sorted[i].totalRuns / (float)sorted[i].totalWickets;
        cout << left << setw(25) << sorted[i].fullName
             << setw(10) << sorted[i].totalWickets
             << setw(12) << fixed << setprecision(2) << sorted[i].economyRate
             << setw(10) << sorted[i].totalOvers
             << setw(10) << sorted[i].matches
             << fixed << setprecision(2) << average << endl;
    }
    cout << string(100, '-') << endl;
}

// Print season-wise dot ball specialists
void printSeasonDotBallSpecialists(const vector<BowlingCard>& data, int targetSeason, float minOvers = 20.0, int topN = 10) {
    vector<SeasonBowlingStats> seasonStats = calculateSeasonStats(data);
    
    // Filter for target season and sort by dot ball percentage
    vector<SeasonBowlingStats> sorted;
    for(const auto& stats : seasonStats) {
        if(stats.season == targetSeason && stats.totalOvers >= minOvers) {
            sorted.push_back(stats);
        }
    }
    
    sort(sorted.begin(), sorted.end(), 
        [](const SeasonBowlingStats& a, const SeasonBowlingStats& b) {
            float a_dot_percent = (a.totalDots / (a.totalOvers * 6.0f)) * 100;
            float b_dot_percent = (b.totalDots / (b.totalOvers * 6.0f)) * 100;
            return a_dot_percent > b_dot_percent;
        });

    cout << "\nTop " << topN << " Dot Ball Specialists for Season " << targetSeason 
         << " (min " << minOvers << " overs):\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(15) << "Dot Ball %"
         << setw(10) << "Dots"
         << setw(10) << "Overs"
         << setw(12) << "Economy"
         << "Matches" << endl;
    cout << string(100, '-') << endl;

    for(int i = 0; i < min(topN, (int)sorted.size()); i++) {
        float dot_percentage = (sorted[i].totalDots / (sorted[i].totalOvers * 6.0f)) * 100;
        cout << left << setw(25) << sorted[i].fullName
             << setw(15) << fixed << setprecision(2) << dot_percentage
             << setw(10) << sorted[i].totalDots
             << setw(10) << sorted[i].totalOvers
             << setw(12) << sorted[i].economyRate
             << sorted[i].matches << endl;
    }
    cout << string(100, '-') << endl;
}

// Print season-wise maiden specialists
void printSeasonMaidenSpecialists(const vector<BowlingCard>& data, int targetSeason, float minOvers = 20.0, int topN = 10) {
    vector<SeasonBowlingStats> seasonStats = calculateSeasonStats(data);
    
    // Filter for target season and sort by maiden percentage
    vector<SeasonBowlingStats> sorted;
    for(const auto& stats : seasonStats) {
        if(stats.season == targetSeason && stats.totalOvers >= minOvers) {
            sorted.push_back(stats);
        }
    }
    
    sort(sorted.begin(), sorted.end(), 
        [](const SeasonBowlingStats& a, const SeasonBowlingStats& b) {
            float a_maiden_percent = (a.totalMaidens / a.totalOvers) * 100;
            float b_maiden_percent = (b.totalMaidens / a.totalOvers) * 100;
            return a_maiden_percent > b_maiden_percent;
        });

    cout << "\nTop " << topN << " Maiden Specialists for Season " << targetSeason 
         << " (min " << minOvers << " overs):\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(15) << "Maiden %"
         << setw(10) << "Maidens"
         << setw(10) << "Overs"
         << setw(12) << "Economy"
         << "Matches" << endl;
    cout << string(100, '-') << endl;

    for(int i = 0; i < min(topN, (int)sorted.size()); i++) {
        float maiden_percentage = (sorted[i].totalMaidens / sorted[i].totalOvers) * 100;
        cout << left << setw(25) << sorted[i].fullName
             << setw(15) << fixed << setprecision(2) << maiden_percentage
             << setw(10) << sorted[i].totalMaidens
             << setw(10) << sorted[i].totalOvers
             << setw(12) << sorted[i].economyRate
             << sorted[i].matches << endl;
    }
    cout << string(100, '-') << endl;
}

void printTopRunScorers(const vector<BattingCard>& data, int topN = 10) {
    vector<BattingCard> sorted = data;
    // Using our custom QuickSort instead of std::sort
    quickSortBattingCards(sorted, 0, sorted.size() - 1);

    cout << "Top " << topN << " Individual Run Scorers of all time:\n";
    cout << string(85, '-') << endl;
    cout << left << setw(25) << "Player" << setw(10) << "Runs" << setw(15) << "Match" << endl;
    cout << string(85, '-') << endl;
    for (int i = 0; i < min(topN, (int)sorted.size()); ++i) {
        cout << left << setw(25) << sorted[i].fullName
             << setw(10) << sorted[i].runs
             << setw(15) << sorted[i].match_name << endl;
    }
    cout << string(85, '-') << endl;
}

// Print top N by strike rate (min balls faced filter)
void printTopStrikeRate(const vector<BattingCard>& data, int minBalls = 10, int topN = 10) {
    vector<BattingCard> sorted = data;
    // Using our custom MergeSort instead of std::sort
    mergeSortBattingCardsByStrikeRate(sorted, 0, sorted.size() - 1);

    cout << "Top " << topN << " Strike Rates (min " << minBalls << " balls):\n";
    cout << string(85, '-') << endl;
    cout << left << setw(25) << "Player" << setw(15) << "Strike Rate" << setw(10) << "Runs" << endl;
    cout << string(85, '-') << endl;
    for (int i = 0; i < min(topN, (int)sorted.size()); ++i) {
        if (sorted[i].runs >= minBalls) {
            cout << left << setw(25) << sorted[i].fullName
                 << setw(15) << sorted[i].strikeRate
                 << setw(10) << sorted[i].runs << endl;
        }
    }
    cout << string(85, '-') << endl;
}

// Print top N six hitters for a specific season
void printTopSixHitters(const vector<BattingCard>& data, int targetSeason, int topN = 10) {
    vector<SeasonBattingStats> seasonStats = calculateSeasonBattingStats(data, targetSeason);
    
    // Sort by number of sixes
    sort(seasonStats.begin(), seasonStats.end(), 
        [](const SeasonBattingStats& a, const SeasonBattingStats& b) {
            return a.totalSixes > b.totalSixes;
        });

    cout << "\nTop " << topN << " Six Hitters for Season " << targetSeason << ":\n";
    cout << string(85, '-') << endl;
    cout << left << setw(25) << "Player" 
         << setw(10) << "Sixes"
         << setw(10) << "Runs"
         << setw(12) << "Strike Rate"
         << setw(10) << "Matches"
         << "Sixes/Match" << endl;
    cout << string(85, '-') << endl;

    for(int i = 0; i < min(topN, (int)seasonStats.size()); i++) {
        float sixesPerMatch = (float)seasonStats[i].totalSixes / seasonStats[i].matches;
        cout << left << setw(25) << seasonStats[i].fullName
             << setw(10) << seasonStats[i].totalSixes
             << setw(10) << seasonStats[i].totalRuns
             << setw(12) << fixed << setprecision(2) << seasonStats[i].avgStrikeRate
             << setw(10) << seasonStats[i].matches
             << fixed << setprecision(2) << sixesPerMatch << endl;
    }
    cout << string(85, '-') << endl;
}

// Function to print top partnerships
void printTopPartnerships(const vector<BallByBallData>& data, int targetSeason, int topN = 3) {
    map<string, Partnership> partnerships;
    
    // Process each ball to track partnerships
    for(const auto& ball : data) {
        if(ball.season == targetSeason) {
            // Create a unique key for each partnership (ensuring consistent ordering)
            string key = ball.match_name;
            key += "-";
            string bat1 = min(string(ball.batsman1_name), string(ball.batsman2_name));
            string bat2 = max(string(ball.batsman1_name), string(ball.batsman2_name));
            key += bat1 + "-" + bat2;
            
            if(partnerships.find(key) == partnerships.end()) {
                Partnership p;
                strcpy(p.batsman1, bat1.c_str());
                strcpy(p.batsman2, bat2.c_str());
                p.totalRuns = 0;
                p.match_name = ball.match_name;
                p.season = ball.season;
                partnerships[key] = p;
            }
            
            // Add runs from this ball to partnership
            partnerships[key].totalRuns += ball.runs;
        }
    }
    
    // Convert to vector for sorting
    vector<Partnership> partnershipList;
    for(const auto& pair : partnerships) {
        partnershipList.push_back(pair.second);
    }
    
    // Sort partnerships by total runs
    sort(partnershipList.begin(), partnershipList.end(),
        [](const Partnership& a, const Partnership& b) {
            return a.totalRuns > b.totalRuns;
        });
    
    // Print top partnerships
    cout << "\nTop " << topN << " Partnerships for Season " << targetSeason << ":\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Batsman 1" 
         << setw(25) << "Batsman 2"
         << setw(15) << "Total Runs"
         << "Match" << endl;
    cout << string(100, '-') << endl;
    
    for(int i = 0; i < min(topN, (int)partnershipList.size()); i++) {
        cout << left << setw(25) << partnershipList[i].batsman1
             << setw(25) << partnershipList[i].batsman2
             << setw(15) << partnershipList[i].totalRuns
             << partnershipList[i].match_name << endl;
    }
    cout << string(100, '-') << endl;
}

void printTopDeathOverBowlers(const vector<BallByBallData>& data, int targetSeason, int topN = 3) {
    map<string, DeathOverStats> deathStats;
    const int DEATH_OVER_START = 16; // Death overs: 16-20
    
    // Process each ball to track death over performances
    for(const auto& ball : data) {
        if(ball.season == targetSeason && ball.over >= DEATH_OVER_START) {
            string bowlerName = ball.bowler1_name;
            
            // Initialize bowler stats if not exists
            if(deathStats.find(bowlerName) == deathStats.end()) {
                DeathOverStats stats;
                strcpy(stats.bowlerName, bowlerName.c_str());
                stats.totalRuns = 0;
                stats.totalBalls = 0;
                stats.wickets = 0;
                stats.matches = 1;
                deathStats[bowlerName] = stats;
            }
            
            // Update stats
            deathStats[bowlerName].totalRuns += ball.runs;
            deathStats[bowlerName].totalBalls++;
            if(strlen(ball.wkt_bowler_name) > 0 && 
               string(ball.wkt_bowler_name) == bowlerName) {
                deathStats[bowlerName].wickets++;
            }
        }
    }
    
    // Calculate economy rates and convert to vector for sorting
    vector<DeathOverStats> bowlerList;
    for(auto& pair : deathStats) {
        if(pair.second.totalBalls >= 30) { // Minimum 5 overs bowled in death
            pair.second.economyRate = 
                (float)(pair.second.totalRuns * 6) / pair.second.totalBalls;
            bowlerList.push_back(pair.second);
        }
    }
    
    // Sort by economy rate
    sort(bowlerList.begin(), bowlerList.end(),
        [](const DeathOverStats& a, const DeathOverStats& b) {
            return a.economyRate < b.economyRate;
        });
    
    // Print top death over bowlers
    cout << "\nTop " << topN << " Death Over Bowlers (overs 16-20) for Season " 
         << targetSeason << ":\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Bowler" 
         << setw(15) << "Economy Rate"
         << setw(15) << "Wickets"
         << setw(15) << "Runs"
         << "Balls" << endl;
    cout << string(100, '-') << endl;
    
    for(int i = 0; i < min(topN, (int)bowlerList.size()); i++) {
        cout << left << setw(25) << bowlerList[i].bowlerName
             << setw(15) << fixed << setprecision(2) << bowlerList[i].economyRate
             << setw(15) << bowlerList[i].wickets
             << setw(15) << bowlerList[i].totalRuns
             << bowlerList[i].totalBalls << endl;
    }
    cout << string(100, '-') << endl;
}

void printTopWinningTeams(const vector<MatchSummary>& summaryData, const vector<BallByBallData>& ballData, int targetSeason, int topN = 3) {
    map<string, TeamSeasonStats> teamStats;
    map<string, string> teamCaptains;
    
    // First, identify captains from ball-by-ball data (usually first batsman of innings)
    for(const auto& ball : ballData) {
        if(ball.season == targetSeason && ball.innings_id == 1) {
            string team = ball.current_innings;
            if(teamCaptains.find(team) == teamCaptains.end()) {
                teamCaptains[team] = ball.batsman1_name;
            }
        }
    }
    
    // Process match summary data to count wins
    for(const auto& match : summaryData) {
        if(match.season == targetSeason) {
            string winner = match.winner;
            
            // Initialize team stats if not exists
            if(teamStats.find(winner) == teamStats.end()) {
                TeamSeasonStats stats;
                strcpy(stats.teamName, winner.c_str());
                if(teamCaptains.find(winner) != teamCaptains.end()) {
                    strcpy(stats.captain, teamCaptains[winner].c_str());
                } else {
                    strcpy(stats.captain, "Unknown");
                }
                stats.wins = 0;
                stats.matches = 0;
                stats.winPercentage = 0.0f;
                teamStats[winner] = stats;
            }
            
            // Update stats
            teamStats[winner].wins++;
            
            // Count total matches for each team
            string homeTeam = match.home_team;
            string awayTeam = match.away_team;
            
            if(teamStats.find(homeTeam) == teamStats.end()) {
                TeamSeasonStats stats;
                strcpy(stats.teamName, homeTeam.c_str());
                if(teamCaptains.find(homeTeam) != teamCaptains.end()) {
                    strcpy(stats.captain, teamCaptains[homeTeam].c_str());
                } else {
                    strcpy(stats.captain, "Unknown");
                }
                stats.wins = 0;
                stats.matches = 0;
                teamStats[homeTeam] = stats;
            }
            if(teamStats.find(awayTeam) == teamStats.end()) {
                TeamSeasonStats stats;
                strcpy(stats.teamName, awayTeam.c_str());
                if(teamCaptains.find(awayTeam) != teamCaptains.end()) {
                    strcpy(stats.captain, teamCaptains[awayTeam].c_str());
                } else {
                    strcpy(stats.captain, "Unknown");
                }
                stats.wins = 0;
                stats.matches = 0;
                teamStats[awayTeam] = stats;
            }
            
            teamStats[homeTeam].matches++;
            teamStats[awayTeam].matches++;
        }
    }
    
    // Calculate win percentages and convert to vector for sorting
    vector<TeamSeasonStats> teamList;
    for(auto& pair : teamStats) {
        if(pair.second.matches > 0) {
            pair.second.winPercentage = (float)pair.second.wins / pair.second.matches * 100;
            teamList.push_back(pair.second);
        }
    }
    
    // Sort by number of wins (primary) and win percentage (secondary)
    sort(teamList.begin(), teamList.end(),
        [](const TeamSeasonStats& a, const TeamSeasonStats& b) {
            if(a.wins == b.wins) {
                return a.winPercentage > b.winPercentage;
            }
            return a.wins > b.wins;
        });
    
    // Print top winning teams
    cout << "\nTop " << topN << " Winning Teams for Season " << targetSeason << ":\n";
    cout << string(100, '-') << endl;
    cout << left << setw(25) << "Team" 
         << setw(25) << "Captain"
         << setw(10) << "Wins"
         << setw(10) << "Matches"
         << "Win %" << endl;
    cout << string(100, '-') << endl;
    
    for(int i = 0; i < min(topN, (int)teamList.size()); i++) {
        cout << left << setw(25) << teamList[i].teamName
             << setw(25) << teamList[i].captain
             << setw(10) << teamList[i].wins
             << setw(10) << teamList[i].matches
             << fixed << setprecision(2) << teamList[i].winPercentage << "%" << endl;
    }
    cout << string(100, '-') << endl;
}

void printHighestScoringTeams(const vector<MatchSummary>& summaryData, int targetSeason, int topN = 3) {
    map<string, TeamScoreStats> teamStats;
    
    // Process match summary data to track scores
    for(const auto& match : summaryData) {
        if(match.season == targetSeason) {
            string homeTeam = match.home_team;
            string awayTeam = match.away_team;
            
            // Initialize home team stats if not exists
            if(teamStats.find(homeTeam) == teamStats.end()) {
                TeamScoreStats stats;
                strcpy(stats.teamName, homeTeam.c_str());
                stats.totalRuns = 0;
                stats.matches = 0;
                stats.averageScore = 0.0f;
                stats.highestScore = 0;
                teamStats[homeTeam] = stats;
            }
            
            // Initialize away team stats if not exists
            if(teamStats.find(awayTeam) == teamStats.end()) {
                TeamScoreStats stats;
                strcpy(stats.teamName, awayTeam.c_str());
                stats.totalRuns = 0;
                stats.matches = 0;
                stats.averageScore = 0.0f;
                stats.highestScore = 0;
                teamStats[awayTeam] = stats;
            }
            
            // Update home team stats
            teamStats[homeTeam].totalRuns += match.home_score;
            teamStats[homeTeam].matches++;
            if(match.home_score > teamStats[homeTeam].highestScore) {
                teamStats[homeTeam].highestScore = match.home_score;
                strcpy(teamStats[homeTeam].highestScoreMatch, match.name);
            }
            
            // Update away team stats
            teamStats[awayTeam].totalRuns += match.away_score;
            teamStats[awayTeam].matches++;
            if(match.away_score > teamStats[awayTeam].highestScore) {
                teamStats[awayTeam].highestScore = match.away_score;
                strcpy(teamStats[awayTeam].highestScoreMatch, match.name);
            }
        }
    }
    
    // Calculate averages and convert to vector for sorting
    vector<TeamScoreStats> teamList;
    for(auto& pair : teamStats) {
        if(pair.second.matches > 0) {
            pair.second.averageScore = (float)pair.second.totalRuns / pair.second.matches;
            teamList.push_back(pair.second);
        }
    }
    
    // Sort by average score (primary) and total runs (secondary)
    sort(teamList.begin(), teamList.end(),
        [](const TeamScoreStats& a, const TeamScoreStats& b) {
            if(abs(a.averageScore - b.averageScore) < 0.01) {
                return a.totalRuns > b.totalRuns;
            }
            return a.averageScore > b.averageScore;
        });
    
    // Print highest scoring teams
    cout << "\nTop " << topN << " Highest Scoring Teams for Season " << targetSeason << ":\n";
    cout << string(120, '-') << endl;
    cout << left << setw(25) << "Team" 
         << setw(15) << "Avg Score"
         << setw(15) << "Total Runs"
         << setw(10) << "Matches"
         << setw(15) << "Highest Score"
         << "Match" << endl;
    cout << string(120, '-') << endl;
    
    for(int i = 0; i < min(topN, (int)teamList.size()); i++) {
        cout << left << setw(25) << teamList[i].teamName
             << setw(15) << fixed << setprecision(2) << teamList[i].averageScore
             << setw(15) << teamList[i].totalRuns
             << setw(10) << teamList[i].matches
             << setw(15) << teamList[i].highestScore
             << teamList[i].highestScoreMatch << endl;
    }
    cout << string(120, '-') << endl;
}

void printHighestTeamScore(const vector<MatchSummary>& summaryData, int targetSeason) {
    int highestScore = 0;
    string teamName;
    string matchName;
    string opponent;
    
    // Process match summary data to find highest score
    for(const auto& match : summaryData) {
        if(match.season == targetSeason) {
            // Check home team score
            if(match.home_score > highestScore) {
                highestScore = match.home_score;
                teamName = match.home_team;
                matchName = match.name;
                opponent = match.away_team;
            }
            
            // Check away team score
            if(match.away_score > highestScore) {
                highestScore = match.away_score;
                teamName = match.away_team;
                matchName = match.name;
                opponent = match.home_team;
            }
        }
    }
    
    // Print result
    cout << "\nHighest Team Score in Season " << targetSeason << ":\n";
    cout << string(100, '-') << endl;
    cout << "Score: " << highestScore << "\n";
    cout << "Team: " << teamName << "\n";
    cout << "Against: " << opponent << "\n";
    cout << "Match: " << matchName << "\n";
    cout << string(100, '-') << endl;
}

void printMainMenu() {
    printMenuHeader("MAIN MENU");
    cout << "\nChoose Analysis Category:\n";
    cout << "1. Batting Statistics\n";
    cout << "2. Bowling Statistics\n";
    cout << "3. Team Statistics\n";
    cout << "4. Partnership Analysis\n";
    cout << "5. Exit Program\n";
    cout << "\nEnter your choice (1-5): ";
}

void printBattingMenu() {
    printMenuHeader("BATTING ANALYSIS");
    cout << "\nSelect Analysis Type:\n";
    cout << "1. All-time Top Run Scorers\n";
    cout << "2. Best Strike Rates\n";
    cout << "3. Season's Top Six Hitters\n";
    cout << "4. Return to Main Menu\n";
    cout << "\nEnter your choice (1-4): ";
}

void printBowlingMenu() {
    printMenuHeader("BOWLING ANALYSIS");
    cout << "\nSelect Analysis Type:\n";
    cout << "1. Season's Most Economical Bowlers\n";
    cout << "2. Season's Top Wicket Takers\n";
    cout << "3. Season's Best Dot Ball Specialists\n";
    cout << "4. Season's Maiden Over Specialists\n";
    cout << "5. Season's Best Death Over Bowlers\n";
    cout << "6. Return to Main Menu\n";
    cout << "\nEnter your choice (1-6): ";
}

void printTeamMenu() {
    printMenuHeader("TEAM ANALYSIS");
    cout << "\nSelect Analysis Type:\n";
    cout << "1. Season's Top Winning Teams\n";
    cout << "2. Season's Highest Scoring Teams\n";
    cout << "3. Season's Highest Team Score\n";
    cout << "4. Return to Main Menu\n";
    cout << "\nEnter your choice (1-4): ";
}

void clearScreen() {
    cout << string(100, '\n');
}

int main() 
{
    // Show loading indicator while loading data
    showLoadingIndicator("Loading batting data...");
    vector<BattingCard> battingData = battingdata("D:/FLAME_UG/UG2/DSA/DSA Project/all_season_batting_card.csv");
    
    showLoadingIndicator("Loading bowling data...");
    vector<BowlingCard> bowlingData = bowlingdata("D:/FLAME_UG/UG2/DSA/DSA Project/all_season_bowling_card.csv");
    
    showLoadingIndicator("Loading ball-by-ball data...");
    vector<BallByBallData> ballData = readBallByBallData("D:/FLAME_UG/UG2/DSA/DSA Project/all_season_details.csv");
    
    showLoadingIndicator("Loading match summary data...");
    vector<MatchSummary> summaryData = readMatchSummaryData("D:/FLAME_UG/UG2/DSA/DSA Project/all_season_summary.csv");

    bool running = true;
    while(running) {
        clearScreen();
        printMainMenu();
        int choice = getValidInput(1, 5);

        switch(choice) {
            case 1: { // Batting Analysis
                bool battingMenu = true;
                while(battingMenu) {
                    clearScreen();
                    printBattingMenu();
                    int battingChoice = getValidInput(1, 4);
                    
                    clearScreen();
                    switch(battingChoice) {
                        case 1:
                            showLoadingIndicator("Analyzing top run scorers...");
                            printTopRunScorers(battingData, 10);
                            break;
                        case 2: {
                            int minBalls = (int)getValidFloat(1, 1000, "Enter minimum balls faced (1-1000): ");
                            showLoadingIndicator("Analyzing strike rates...");
                            printTopStrikeRate(battingData, minBalls, 10);
                            break;
                        }
                        case 3: {
                            int season = (int)getValidFloat(2008, 2024, "Enter season (2008-2024): ");
                            showLoadingIndicator("Analyzing six hitters...");
                            printTopSixHitters(battingData, season, 10);
                            break;
                        }
                        case 4:
                            battingMenu = false;
                            continue;
                    }
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                break;
            }
            
            case 2: { // Bowling Analysis
                bool bowlingMenu = true;
                while(bowlingMenu) {
                    clearScreen();
                    printBowlingMenu();
                    int bowlingChoice = getValidInput(1, 6);
                    
                    if(bowlingChoice == 6) {
                        bowlingMenu = false;
                        continue;
                    }

                    clearScreen();
                    int season = (int)getValidFloat(2008, 2024, "Enter season (2008-2024): ");
                    float minOvers = getValidFloat(1, 100, "Enter minimum overs bowled (1-100): ");
                    
                    showLoadingIndicator("Analyzing bowling statistics...");
                    switch(bowlingChoice) {
                        case 1:
                            printSeasonEconomicalBowlers(bowlingData, season, minOvers, 10);
                            break;
                        case 2:
                            printSeasonWicketTakers(bowlingData, season, minOvers, 10);
                            break;
                        case 3:
                            printSeasonDotBallSpecialists(bowlingData, season, minOvers, 10);
                            break;
                        case 4:
                            printSeasonMaidenSpecialists(bowlingData, season, minOvers, 10);
                            break;
                        case 5:
                            printTopDeathOverBowlers(ballData, season, 3);
                            break;
                    }
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                break;
            }
            
            case 3: { // Team Analysis
                bool teamMenu = true;
                while(teamMenu) {
                    clearScreen();
                    printTeamMenu();
                    int teamChoice = getValidInput(1, 4);
                    
                    if(teamChoice == 4) {
                        teamMenu = false;
                        continue;
                    }

                    clearScreen();
                    int season = (int)getValidFloat(2008, 2024, "Enter season (2008-2024): ");
                    
                    showLoadingIndicator("Analyzing team statistics...");
                    switch(teamChoice) {
                        case 1:
                            printTopWinningTeams(summaryData, ballData, season, 3);
                            break;
                        case 2:
                            printHighestScoringTeams(summaryData, season, 3);
                            break;
                        case 3:
                            printHighestTeamScore(summaryData, season);
                            break;
                    }
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                break;
            }
            
            case 4: { // Partnership Analysis
                clearScreen();
                int season = (int)getValidFloat(2008, 2024, "Enter season (2008-2024): ");
                showLoadingIndicator("Analyzing partnerships...");
                printTopPartnerships(ballData, season, 3);
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }
            
            case 5: // Exit
                running = false;
                cout << "\nThank you for using IPL Data Analysis Dashboard!\n";
                break;
        }
    }

    return 0;
}
