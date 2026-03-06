import tkinter as tk
from tkinter import ttk, messagebox
import mysql.connector

# Connecting to MySQL database
conn = mysql.connector.connect(
    host="localhost",
    user="root",    
    password="omkarsql",    
    database="IPL_Database"  
)

cursor = conn.cursor()

def run_query(query, params=()):
    try:
        cursor.execute(query, params)
        return cursor.fetchall(), [i[0] for i in cursor.description]
    except mysql.connector.Error as err:
        messagebox.showerror("Database Error", str(err))
        return [], []


def show_results(title, query, params=()):
    results, columns = run_query(query, params)
    if not results:
        return

    win = tk.Toplevel(root)
    win.title(title)
    win.geometry("850x400")

    tree = ttk.Treeview(win, columns=columns, show='headings')
    for col in columns:
        tree.heading(col, text=col)
        tree.column(col, width=150, anchor='center')

    for row in results:
        tree.insert("", "end", values=row)

    tree.pack(expand=True, fill='both')

    sx = ttk.Scrollbar(win, orient="horizontal", command=tree.xview)
    sy = ttk.Scrollbar(win, orient="vertical", command=tree.yview)
    tree.configure(xscrollcommand=sx.set, yscrollcommand=sy.set)
    sx.pack(fill='x', side='bottom')
    sy.pack(fill='y', side='right')


root = tk.Tk()
root.title("IPL 2024 Query Explorer")
root.geometry("1000x400")

frame = tk.LabelFrame(root, text="Choose Query Options", padx=10, pady=10)
frame.pack(padx=10, pady=10, fill="x")

venue_input = tk.StringVar()
teams_input = tk.StringVar()
captain_input = tk.StringVar()

venue_list = [
    " "
    "MA Chidambaram Stadium, Chepauk, Chennai",
    "Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur",
    "Eden Gardens, Kolkata",
    "Sawai Mansingh Stadium, Jaipur",
    "Narendra Modi Stadium, Motera, Ahmedabad",
    "M.Chinnaswamy Stadium, Bengaluru",
    "Rajiv Gandhi International Stadium, Uppal, Hyderabad",
    "Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow",
    "Dr. Y.S. Rajasekhara Reddy ACA-VDCA Cricket Stadium, Visakhapatnam",
    "Wankhede Stadium, Mumbai",
    "Arun Jaitley Stadium, Delhi",
    "Himachal Pradesh Cricket Association Stadium, Dharamsala"
]

team_list = [
    " ", "CSK", "PBKS", "KKR", "RR", "GT", "RCB", "SRH", "LSG", "DC", "MI"
]

captain_list = [
    " ", "Ruturaj Gaikwad", "Shikhar Dhawan", "Shreyas Iyer", "Sanju Samson", "Shubman Gill",
    "Faf du Plessis", "Pat Cummins", "Nicholas Pooran", "Rishabh Pant", "Hardik Pandya",
    "KL Rahul", "Sam Curran"
]


entries = [
    ("Venue Name:", venue_input, venue_list),
    ("Team Name:", teams_input, team_list),
    ("Captain Name:", captain_input, captain_list),
]

for i, (label, var, options) in enumerate(entries):
    tk.Label(frame, text=label).grid(row=0, column=i*2)
    dropdown = ttk.Combobox(frame, textvariable=var, values=options, state="readonly", width=30)
    dropdown.grid(row=0, column=i*2+1)


btn_frame = tk.Frame(root)
btn_frame.pack(pady=10)


btn_frame = tk.Frame(root)
btn_frame.pack(pady=10)

#queries in the UI:
queries = [
    ("Top 5 Avg Home Scores", 
     "SELECT home_team, AVG(SUBSTRING_INDEX(home_score, '/', 1) + 0) AS avg_score FROM Match_Details GROUP BY home_team ORDER BY avg_score DESC LIMIT 5"),

    ("Top 5 Matches in aggregated scores",
     "SELECT  s.Match_ID,  m.match_name, (s.home_runs + s.away_runs) AS total_runs FROM  Score_Details s JOIN  Match_Details m ON s.Match_ID = m.Match_ID ORDER BY  total_runs DESC LIMIT 5;"),

    ("Top 5 PoM Awardees",
     "SELECT Player_of_the_Match, COUNT(*) AS awards FROM Score_Details GROUP BY Player_of_the_Match ORDER BY awards DESC LIMIT 5"),

    ("Most Frequent key batsmen partnership",
     """SELECT key_batsman, COUNT(*) AS appearances
        FROM (
            SELECT home_key_batsman AS key_batsman FROM key_players
            UNION ALL
            SELECT away_key_batsman AS key_batsman FROM key_players
        ) AS combined
        GROUP BY key_batsman
        ORDER BY appearances DESC
        LIMIT 5;"""),


    ("Most Frequent Winner at Selected Venue",
     lambda: show_results("Wins at Venue", 
        "SELECT md.winner, COUNT(*) AS win_count FROM Match_Details md JOIN venue_details vd ON md.Match_ID = vd.Match_ID WHERE vd.venue_name = %s AND md.winner IS NOT NULL GROUP BY md.winner ORDER BY win_count DESC LIMIT 1", 
        (venue_input.get(),))),
    
    ("Number of Wins by Team in Season (2024)",
     lambda: show_results("Team Wins in 2024", 
        "SELECT winner, COUNT(*) AS wins FROM Match_Details WHERE season = 2024 AND winner = %s GROUP BY winner", 
        (teams_input.get(),))),
    
    ("Matches Captained by a Selected Captain",
     lambda: show_results("Matches by Captain",
                          """SELECT 
    cd.Match_ID,
    cd.home_captain,
    cd.away_captain,
    md.winner,
    CASE
        WHEN cd.home_captain = %s AND md.winner = md.home_team THEN 'Won'
        WHEN cd.away_captain = %s AND md.winner = md.away_team THEN 'Won'
        ELSE 'Lost'
    END AS captain_result
FROM 
    captain_names cd
JOIN 
    match_details md ON cd.Match_ID = md.Match_ID
WHERE 
    cd.home_captain = %s OR cd.away_captain = %s;""",
        (captain_input.get(), captain_input.get(), captain_input.get(), captain_input.get(),))),

    ("Avg Runs by selected Team at Selected Venue",
     lambda: show_results("Avg Runs by Team at Venue", 
        """SELECT 
                combined.team_name, 
                combined.venue_name, 
                ROUND(AVG(combined.runs_scored), 2) AS avg_runs
            FROM (
                SELECT 
                    md.home_team AS team_name, 
                    mv.venue_name, 
                    s.home_runs AS runs_scored
                FROM 
                    Score_Details s
                JOIN Match_Details md ON s.Match_ID = md.Match_ID
                JOIN venue_details mv ON md.Match_ID = mv.Match_ID
                WHERE md.home_team = %s AND mv.venue_name = %s

                UNION ALL

                SELECT 
                    md.away_team AS team_name, 
                    mv.venue_name, 
                    s.away_runs AS runs_scored
                FROM 
                    Score_Details s
                JOIN Match_Details md ON s.Match_ID = md.Match_ID
                JOIN venue_details mv ON md.Match_ID = mv.Match_ID
                WHERE md.away_team = %s AND mv.venue_name = %s
            ) AS combined
            GROUP BY combined.team_name, combined.venue_name;""", 
        (teams_input.get(), venue_input.get(), teams_input.get(), venue_input.get()))),
        
    ("Team's Favorite Winning Venue (most wins at a venue)",
     lambda: show_results("Team's Favorite Venue", 
        "SELECT venue_name, COUNT(*) AS win_count FROM Match_Details md JOIN venue_details mv ON md.Match_ID = mv.Match_ID WHERE md.winner = %s GROUP BY venue_name ORDER BY win_count DESC LIMIT 1", 
        (teams_input.get(),))),
]


for idx, q in enumerate(queries[:4]):
    tk.Button(btn_frame, text=q[0], width=30, command=lambda query=q[1], title=q[0]: show_results(title, query)).grid(row=idx//2, column=idx%2, padx=5, pady=5)


for idx, q in enumerate(queries[4:]):
    tk.Button(btn_frame, text=q[0], width=40, command=q[1]).grid(row=2 + idx, column=0, columnspan=2, pady=5)

root.mainloop()


cursor.close()
conn.close()
