PRAGMA foreign_keys = ON;

--------------------------------------------------------
-- 1. FELHASZNÁLÓK TÁBLÁJA //VIKTÓRIA
--------------------------------------------------------
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL
);

-- Alapértelmezett teszt felhasználó
INSERT OR IGNORE INTO users (id, username, password)
VALUES (1, 'demo_jatekos', 'demo123');

--------------------------------------------------------
-- 2. KÉRDÉSEK TÁBLÁJA // PÁLL LÁSZLÓ
--------------------------------------------------------
CREATE TABLE IF NOT EXISTS questions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    -- enumnak megfelelő számok:
    -- language:    0=HU, 1=EN, 2=DE, 3=RU
    -- category:    0=Vocabulary, 1=Grammar, 2=Sentences, 3=Listening
    -- difficulty:  0=Beginner, 1=Intermediate, 2=Advanced

    language INTEGER NOT NULL,
    category INTEGER NOT NULL,
    difficulty INTEGER NOT NULL,

    question_text TEXT NOT NULL,
    word TEXT NOT NULL,

    answer_a TEXT NOT NULL,
    answer_b TEXT NOT NULL,
    answer_c TEXT NOT NULL,
    answer_d TEXT NOT NULL,

    correct_answer INTEGER NOT NULL,
    points INTEGER NOT NULL DEFAULT 1
);

--------------------------------------------------------
-- 2.a MINTA KÉRDÉSEK
--------------------------------------------------------
INSERT INTO questions (
    language, category, difficulty,
    question_text, word,
    answer_a, answer_b, answer_c, answer_d,
    correct_answer, points
) VALUES

--------------------------------------------------------
-- HUNGARIAN (0) – Vocabulary (0)
--------------------------------------------------------

-- === Beginner (0) ===
(0,0,0,'Mit jelent angolul?','alma', 'apple','pear','plum','banana',0,1),
(0,0,0,'Mit jelent angolul?','kutya', 'cat','mouse','dog','bird',2,1),
(0,0,0,'Mit jelent angolul?','ház', 'house','garden','street','city',0,1),
(0,0,0,'Mit jelent angolul?','víz', 'fire','air','water','earth',2,1),
(0,0,0,'Mit jelent angolul?','asztal', 'chair','table','bed','lamp',1,1),
(0,0,0,'Mit jelent angolul?','piros', 'blue','green','yellow','red',3,1),
(0,0,0,'Mit jelent angolul?','anya', 'mother','father','sister','brother',0,1),
(0,0,0,'Mit jelent angolul?','könyv', 'pen','book','paper','pencil',1,1),
(0,0,0,'Mit jelent angolul?','autó', 'bus','train','car','bike',2,1),
(0,0,0,'Mit jelent angolul?','nap', 'moon','star','sky','sun',3,1),
(0,0,0,'Mit jelent angolul?','kenyér', 'bread','milk','butter','cheese',0,1),
(0,0,0,'Mit jelent angolul?','iskola', 'shop','cinema','school','park',2,1),
(0,0,0,'Mit jelent angolul?','ajtó', 'window','door','wall','roof',1,1),
(0,0,0,'Mit jelent angolul?','szék', 'table','sofa','chair','desk',2,1),
(0,0,0,'Mit jelent angolul?','pénz', 'time','love','work','money',3,1),

-- === Intermediate (1) ===
(0,0,1,'Mit jelent angolul?','barát', 'enemy','friend','neighbor','stranger',1,1),
(0,0,1,'Mit jelent angolul?','megoldás', 'problem','question','solution','mistake',2,1),
(0,0,1,'Mit jelent angolul?','szabadság', 'freedom','prison','law','security',0,1),
(0,0,1,'Mit jelent angolul?','győzelem', 'defeat','game','victory','draw',2,1),
(0,0,1,'Mit jelent angolul?','veszélyes', 'safe','dangerous','easy','hard',1,1),
(0,0,1,'Mit jelent angolul?','emlékszik', 'forget','think','dream','remember',3,1),
(0,0,1,'Mit jelent angolul?','tapasztalat', 'experience','knowledge','idea','skill',0,1),
(0,0,1,'Mit jelent angolul?','lehetőség', 'change','luck','opportunity','risk',2,1),
(0,0,1,'Mit jelent angolul?','különbség', 'difference','similarity','same','equal',0,1),
(0,0,1,'Mit jelent angolul?','döntés', 'result','cause','decision','effect',2,1),
(0,0,1,'Mit jelent angolul?','vélemény', 'fact','opinion','truth','lie',1,1),
(0,0,1,'Mit jelent angolul?','felelősség', 'power','duty','responsibility','right',2,1),
(0,0,1,'Mit jelent angolul?','siker', 'failure','hope','success','plan',2,1),
(0,0,1,'Mit jelent angolul?','utazás', 'stay','journey','home','place',1,1),
(0,0,1,'Mit jelent angolul?','érzelem', 'emotion','thought','action','word',0,1),

-- === Advanced (2) ===
(0,0,2,'Mit jelent angolul?','környezet', 'environment','surrounding','weather','mood',0,1),
(0,0,2,'Mit jelent angolul?','fenntartható', 'sustainable','temporary','wasteful','expensive',0,1),
(0,0,2,'Mit jelent angolul?','következmény', 'cause','origin','consequence','reason',2,1),
(0,0,2,'Mit jelent angolul?','kivétel', 'rule','standard','exception','average',2,1),
(0,0,2,'Mit jelent angolul?','egybeesés', 'plan','coincidence','intention','schedule',1,1),
(0,0,2,'Mit jelent angolul?','elkerülhetetlen', 'possible','avoidable','inevitable','uncertain',2,1),
(0,0,2,'Mit jelent angolul?','ellentmondás', 'agreement','harmony','contradiction','proof',2,1),
(0,0,2,'Mit jelent angolul?','kétértelmű', 'clear','ambiguous','simple','direct',1,1),
(0,0,2,'Mit jelent angolul?','megvalósít', 'dream','fail','implement','ignore',2,1),
(0,0,2,'Mit jelent angolul?','kétségbeesett', 'desperate','calm','hopeful','happy',0,1),
(0,0,2,'Mit jelent angolul?','elavult', 'modern','new','obsolete','fresh',2,1),
(0,0,2,'Mit jelent angolul?','jelentős', 'tiny','minor','substantial','weak',2,1),
(0,0,2,'Mit jelent angolul?','szándékos', 'accidental','random','intentional','lucky',2,1),
(0,0,2,'Mit jelent angolul?','hanyatlás', 'growth','rise','decline','peak',2,1),
(0,0,2,'Mit jelent angolul?','meggyőz', 'convince','dissuade','agree','listen',0,1),

--------------------------------------------------------
-- HUNGARIAN – Grammar (1)
--------------------------------------------------------

-- === Beginner (0) ===
(0,1,0,'Válaszd ki a helyes alakot!','Én ___ tanulok.', 'van','vagyok','leszek','volt',1,1),
(0,1,0,'Válaszd ki a helyes alakot!','Te ___ a barátom.', 'vagyok','vagy','van','lesz',1,1),
(0,1,0,'Válaszd ki a helyes alakot!','Az alma ___ asztalon van.', 'a','az','egy','ez',1,1),
(0,1,0,'Egészítsd ki!','Én Budapesten ___ .', 'lakom','laksz','lakik','lakunk',0,1),
(0,1,0,'Hogy mondjuk helyesen?','Két ___ van.', 'kutya','kutyák','kutyát','kutyának',0,1),
(0,1,0,'Válaszd ki a helyes ragot!','Az iskolá___ megyek.', '-ban','-ból','-ba','-hoz',2,1),
(0,1,0,'Válaszd ki a helyes alakot!','Mi magyarok ___.', 'vagyunk','vagytok','vannak','vagy',0,1),
(0,1,0,'Egészítsd ki!','Nekem ___ egy macskám.', 'van','vagyok','lesz','nincs',0,1),
(0,1,0,'Válaszd ki a helyes névelőt!','Ez ___ autó.', 'egy','az','a','itt',0,1),
(0,1,0,'Hogy mondjuk helyesen?','Öt ___ kérek.', 'almák','alma','almát','almának',2,1),
(0,1,0,'Válaszd ki a helyes alakot!','Ti honnan ___?', 'jöttök','jövünk','jön','jössz',0,1),
(0,1,0,'Egészítsd ki!','A könyv a táskában ___.', 'van','vannak','lesz','volt',0,1),
(0,1,0,'Válaszd ki a helyes ragot!','A ház___ vagyok.', '-ban','-ba','-ból','-hoz',0,1),
(0,1,0,'Válaszd ki a helyes alakot!','Péter és Anna ___ .', 'tanulnak','tanul','tanulok','tanulsz',0,1),
(0,1,0,'Egészítsd ki!','Szeretem a ___ .', 'csoki','csokit','csokik','csokival',1,1),

-- === Intermediate (1) ===
(0,1,1,'Egészítsd ki a mondatot!','Holnap ___ moziba megyünk.', 'talán','biztos','már','nem',0,1),
(0,1,1,'Múlt idő','Tegnap ___ a boltba.', 'megyek','mentem','fogok menni','mennék',1,1),
(0,1,1,'Jövő idő','Jövőre egyetemen ___ tanulni.', 'fogok','szoktam','tudok','akarok',0,1),
(0,1,1,'Feltételes mód','Ha lenne pénzem, ___ egy házat.', 'vennék','veszek','vettem','venni',0,1),
(0,1,1,'Igekötők','Mikor ___ haza?', 'mész','jössz','érkezel','indulsz',1,1),
(0,1,1,'Birtokos eset','Ez a ___ könyve.', 'fiú','fiúk','fiúé','fiúnak',0,1),
(0,1,1,'Többesszám birtokos','Ezek az én ___ .', 'könyveim','könyvem','könyvek','könyvei',0,1),
(0,1,1,'Kötőszavak','Szeretem a teát, ___ a kávét nem.', 'de','és','vagy','mert',0,1),
(0,1,1,'Felszólító mód','___ ki az ablakot!', 'Nyisd','Nyitod','Nyitni','Nyitott',0,1),
(0,1,1,'Melyik a helyes?','Nem ___ úszni.', 'tudok','ismerem','birok','lehet',0,1),
(0,1,1,'Ragozás','Beszélek ___ .', 'magyarul','magyar','magyart','magyaran',0,1),
(0,1,1,'Névutók','A macska az asztal ___ van.', 'alatt','alól','alá','alul',0,1),
(0,1,1,'Tagadás','Soha ___ voltam Párizsban.', 'nem','sem','se','ne',0,1),
(0,1,1,'Kérdőszó','___ kerül ez a ruha?', 'Mennyibe','Hány','Mikor','Hol',0,1),
(0,1,1,'Egészítsd ki!','Mindenki ___ a buliban.', 'ott volt','elment','látta','jött',0,1),

-- === Advanced (2) ===
(0,1,2,'Melyik a helyes?','Ha több pénzem ___, utaznék.', 'lenne','van','volt','lesz',0,1),
(0,1,2,'Feltételes múlt','Ha tudtam volna, ___ .', 'segítettem volna','segítek','segítenék','segítettem',0,1),
(0,1,2,'Szenvedő szerkezet (ritka)','Az ebéd meg ___ főzve.', 'van','lesz','volt','kell',0,1),
(0,1,2,'Kötőszavak','___ esik az eső, elmegyünk sétálni.', 'Noha','Mert','Hogy','Amint',0,1),
(0,1,2,'Műveltető ige','Levágatom a ___ .', 'hajamat','hajat','hajam','hajammal',0,1),
(0,1,2,'Vonzatok','Félek a ___ .', 'sötéttől','sötétben','sötétre','sötét',0,1),
(0,1,2,'Határozók','___ érkezett a vendég.', 'Váratlanul','Váratlan','Várva','Vár',0,1),
(0,1,2,'Idegen szavak ragozása','A ___ találkozunk.', 'shopban','shoppal','shophoz','shop',0,1),
(0,1,2,'Birtokos többes','A szomszédaim___ kutyája ugat.', 'nak a','nak','é','a',0,1),
(0,1,2,'Átvitt értelem','Ez nekem ___ .', 'kínai','olasz','angol','német',0,1),
(0,1,2,'Kötőmód','Azt akarom, hogy ___ .', 'menj','mégy','menni','mentél',0,1),
(0,1,2,'Igekötők jelentése','Be___ a gyógyszert.', 'vette','adta','tette','hozta',0,1),
(0,1,2,'Szórend','Tegnap ___ moziba.', 'mentem','én','a','voltam',0,1),
(0,1,2,'Kifejezések','___ van a nyelvemen.', 'Itt','Ott','Ez','Most',0,1),
(0,1,2,'Névelőhasználat','A Duna ___ leghosszabb folyó.', 'a','egy','az','-',0,1),

--------------------------------------------------------
-- HUNGARIAN – Sentences (2)
--------------------------------------------------------

-- === Beginner (0) ===
(0,2,0,'Hogyan mondod angolul?','Hány éves vagy?', 'How old are you?','How are you?','Where are you?','What age you?',0,1),
(0,2,0,'Hogyan mondod angolul?','Jó reggelt!', 'Good morning!','Good night!','Hello!','Good bye!',0,1),
(0,2,0,'Hogyan mondod angolul?','Köszönöm.', 'Thank you.','Please.','Sorry.','Excuse me.',0,1),
(0,2,0,'Hogyan mondod angolul?','Viszlát!', 'Goodbye!','Hi!','Welcome!','Good day!',0,1),
(0,2,0,'Hogyan mondod angolul?','Bocsánat.', 'Sorry.','Thanks.','Please.','Good.',0,1),
(0,2,0,'Hogyan mondod angolul?','Nem értem.', 'I do not understand.','I know.','I think so.','Yes please.',0,1),
(0,2,0,'Hogyan mondod angolul?','Igen.', 'Yes.','No.','Maybe.','Sure.',0,1),
(0,2,0,'Hogyan mondod angolul?','Nem.', 'No.','Yes.','Okay.','Fine.',0,1),
(0,2,0,'Hogyan mondod angolul?','Hogy hívnak?', 'What is your name?','Who are you?','Where are you?','How are you?',0,1),
(0,2,0,'Hogyan mondod angolul?','Éhes vagyok.', 'I am hungry.','I am thirsty.','I am tired.','I am happy.',0,1),
(0,2,0,'Hogyan mondod angolul?','Szeretem a zenét.', 'I like music.','I hate music.','I play music.','Music is good.',0,1),
(0,2,0,'Hogyan mondod angolul?','Hol van a WC?', 'Where is the toilet?','Where is the room?','What is that?','Who is he?',0,1),
(0,2,0,'Hogyan mondod angolul?','Mennyi az idő?', 'What time is it?','Where is the time?','Do you have time?','Is it late?',0,1),
(0,2,0,'Hogyan mondod angolul?','Magyar vagyok.', 'I am Hungarian.','I am English.','I speak Hungarian.','Hungary is nice.',0,1),
(0,2,0,'Hogyan mondod angolul?','Segítség!', 'Help!','Run!','Stop!','Go!',0,1),

-- === Intermediate (1) ===
(0,2,1,'Hogyan mondod angolul?','Hol laksz?', 'Where do you live?','Where live you?','Where are you live?','Where are live?',0,1),
(0,2,1,'Hogyan mondod angolul?','Mit dolgozol?', 'What is your job?','What do you work?','Where are you working?','Work you?',0,1),
(0,2,1,'Hogyan mondod angolul?','Szeretek utazni.', 'I like traveling.','I like travel.','I travel like.','Travel is good.',0,1),
(0,2,1,'Hogyan mondod angolul?','Ez túl drága.', 'This is too expensive.','This is cheap.','This is good price.','Big money.',0,1),
(0,2,1,'Hogyan mondod angolul?','Kérhetek egy számlát?', 'Can I have the bill?','Give me money.','Bill please.','What is the price?',0,1),
(0,2,1,'Hogyan mondod angolul?','Nem érzem jól magam.', 'I do not feel well.','I am sick.','I am happy.','I feel good.',0,1),
(0,2,1,'Hogyan mondod angolul?','Mit csinálsz hétvégén?', 'What are you doing on the weekend?','Where go weekend?','Weekend what?','Do you like weekend?',0,1),
(0,2,1,'Hogyan mondod angolul?','Holnap találkozunk.', 'See you tomorrow.','See you later.','Hello tomorrow.','Tomorrow come.',0,1),
(0,2,1,'Hogyan mondod angolul?','Merre van a központ?', 'Which way is the center?','Where is center?','Center where?','Go to center.',0,1),
(0,2,1,'Hogyan mondod angolul?','Beszélsz angolul?', 'Do you speak English?','Speak English?','English you speak?','Are you English?',0,1),
(0,2,1,'Hogyan mondod angolul?','Sajnálom, de nem érek rá.', 'Sorry, I am busy.','Sorry, no time.','I am free.','No problem.',0,1),
(0,2,1,'Hogyan mondod angolul?','Nagyon kedves vagy.', 'You are very kind.','You are good.','Thanks.','You are bad.',0,1),
(0,2,1,'Hogyan mondod angolul?','Mikor indulsz?', 'When do you leave?','When go?','Where are you?','Time to go?',0,1),
(0,2,1,'Hogyan mondod angolul?','Ez egy jó ötlet.', 'That is a good idea.','Good thinking.','Bad idea.','I know.',0,1),
(0,2,1,'Hogyan mondod angolul?','Megismételnéd, kérlek?', 'Could you repeat that please?','Say again.','What?','Repeat.',0,1),

-- === Advanced (2) ===
(0,2,2,'Hogyan mondod angolul?','Mikor érkezel?', 'When will you arrive?','When come you?','When are arrive you?','When do arrive?',0,1),
(0,2,2,'Hogyan mondod angolul?','Attól függ.', 'It depends.','Depending on.','It hangs.','Maybe so.',0,1),
(0,2,2,'Hogyan mondod angolul?','Nem hiszem, hogy ez igaz.', 'I do not think that is true.','Not true think.','Believe not true.','False it is.',0,1),
(0,2,2,'Hogyan mondod angolul?','Ha lett volna időm, elmentem volna.', 'If I had had time, I would have gone.','If I have time I go.','Had I time went.','Time goes.',0,1),
(0,2,2,'Hogyan mondod angolul?','Egyetértek veled.', 'I agree with you.','I am with you.','Same here.','You are right.',0,1),
(0,2,2,'Hogyan mondod angolul?','Kétségkívül ez a legjobb megoldás.', 'Undoubtedly this is the best solution.','Maybe best way.','Sure good.','No doubt good.',0,1),
(0,2,2,'Hogyan mondod angolul?','Meggyőződésem, hogy sikerülni fog.', 'I am convinced it will succeed.','Sure success.','I know win.','Believe win.',0,1),
(0,2,2,'Hogyan mondod angolul?','Feltéve, ha nem esik.', 'Provided it does not rain.','If no rain.','Rain not.','Unless rain.',0,1),
(0,2,2,'Hogyan mondod angolul?','Lényegében igazad van.', 'Essentially, you are right.','Basic right.','Mainly true.','Real correct.',0,1),
(0,2,2,'Hogyan mondod angolul?','Szeretnék panaszt tenni.', 'I would like to make a complaint.','Complaint make.','Bad service.','Problem have.',0,1),
(0,2,2,'Hogyan mondod angolul?','Ez meghaladja a képességeimet.', 'This is beyond my abilities.','Too hard.','Cannot do.','Over me.',0,1),
(0,2,2,'Hogyan mondod angolul?','Minden valószínűség szerint.', 'In all likelihood.','Maybe yes.','Sure.','Probably.',0,1),
(0,2,2,'Hogyan mondod angolul?','Ne csinálj bolhából elefántot!', 'Do not make a mountain out of a molehill.','No elephant.','Small big.','Don''t panic.',0,1),
(0,2,2,'Hogyan mondod angolul?','Jobb későn, mint soha.', 'Better late than never.','Late good.','Never late.','Time is money.',0,1),
(0,2,2,'Hogyan mondod angolul?','Két legyet egy csapásra.', 'Kill two birds with one stone.','Two fly one hit.','Double win.','Hit two.',0,1),

--------------------------------------------------------
-- ENGLISH (1) – Vocabulary (0)m 
--------------------------------------------------------

-- === Beginner (0) ===
(1,0,0,'Mit jelent magyarul?','cat', 'kutya','macska','ló','egér',1,1),
(1,0,0,'Mit jelent magyarul?','dog', 'kutya','macska','madár','hal',0,1),
(1,0,0,'Mit jelent magyarul?','apple', 'alma','körte','szilva','eper',0,1),
(1,0,0,'Mit jelent magyarul?','blue', 'kék','piros','zöld','sárga',0,1),
(1,0,0,'Mit jelent magyarul?','one', 'egy','kettő','három','négy',0,1),
(1,0,0,'Mit jelent magyarul?','mother', 'anya','apa','testvér','nagyi',0,1),
(1,0,0,'Mit jelent magyarul?','house', 'ház','kert','utca','város',0,1),
(1,0,0,'Mit jelent magyarul?','car', 'autó','busz','vonat','bicikli',0,1),
(1,0,0,'Mit jelent magyarul?','book', 'könyv','füzet','toll','ceruza',0,1),
(1,0,0,'Mit jelent magyarul?','water', 'víz','tűz','föld','levegő',0,1),
(1,0,0,'Mit jelent magyarul?','bread', 'kenyér','tej','sajt','vaj',0,1),
(1,0,0,'Mit jelent magyarul?','sun', 'nap','hold','csillag','felhő',0,1),
(1,0,0,'Mit jelent magyarul?','happy', 'boldog','szomorú','mérges','fáradt',0,1),
(1,0,0,'Mit jelent magyarul?','big', 'nagy','kicsi','hosszú','rövid',0,1),
(1,0,0,'Mit jelent magyarul?','milk', 'tej','víz','sör','bor',0,1),

-- === Intermediate (1) ===
(1,0,1,'Mit jelent magyarul?','forest', 'erdő','mező','bokor','sziget',0,1),
(1,0,1,'Mit jelent magyarul?','bridge', 'híd','út','folyó','hegy',0,1),
(1,0,1,'Mit jelent magyarul?','decision', 'döntés','kérdés','válasz','ok',0,1),
(1,0,1,'Mit jelent magyarul?','dangerous', 'veszélyes','biztonságos','gyors','lassú',0,1),
(1,0,1,'Mit jelent magyarul?','success', 'siker','bukás','próba','feladat',0,1),
(1,0,1,'Mit jelent magyarul?','memory', 'emlék','álom','jövő','gondolat',0,1),
(1,0,1,'Mit jelent magyarul?','science', 'tudomány','művészet','sport','zene',0,1),
(1,0,1,'Mit jelent magyarul?','island', 'sziget','tenger','part','hajó',0,1),
(1,0,1,'Mit jelent magyarul?','freedom', 'szabadság','börtön','törvény','jog',0,1),
(1,0,1,'Mit jelent magyarul?','necessary', 'szükséges','felesleges','drága','olcsó',0,1),
(1,0,1,'Mit jelent magyarul?','development', 'fejlődés','romlás','állapot','változás',0,1),
(1,0,1,'Mit jelent magyarul?','stranger', 'idegen','barát','rokon','szomszéd',0,1),
(1,0,1,'Mit jelent magyarul?','immediately', 'azonnal','később','soha','néha',0,1),
(1,0,1,'Mit jelent magyarul?','experience', 'tapasztalat','tudás','könyv','iskola',0,1),
(1,0,1,'Mit jelent magyarul?','solution', 'megoldás','probléma','hiba','terv',0,1),

-- === Advanced (2) ===
(1,0,2,'Mit jelent magyarul?','improvement', 'romlás','fejlődés','kijelentés','megjelenés',1,1),
(1,0,2,'Mit jelent magyarul?','environment', 'környezet','időjárás','természet','világ',0,1),
(1,0,2,'Mit jelent magyarul?','sustainable', 'fenntartható','ideiglenes','káros','drága',0,1),
(1,0,2,'Mit jelent magyarul?','consequence', 'következmény','ok','cél','kezdet',0,1),
(1,0,2,'Mit jelent magyarul?','coincidence', 'véletlen','terv','szándék','sors',0,1),
(1,0,2,'Mit jelent magyarul?','ambiguous', 'kétértelmű','egyértelmű','világos','sötét',0,1),
(1,0,2,'Mit jelent magyarul?','obsolete', 'elavult','modern','új','friss',0,1),
(1,0,2,'Mit jelent magyarul?','inevitable', 'elkerülhetetlen','lehetséges','bizonytalan','kizárt',0,1),
(1,0,2,'Mit jelent magyarul?','substantial', 'jelentős','jelentéktelen','kicsi','kevés',0,1),
(1,0,2,'Mit jelent magyarul?','simultaneously', 'egyszerre','külön','később','előbb',0,1),
(1,0,2,'Mit jelent magyarul?','contradiction', 'ellentmondás','egyetértés','hasonlóság','igazság',0,1),
(1,0,2,'Mit jelent magyarul?','reluctant', 'vonakodó','lelkes','gyors','bátor',0,1),
(1,0,2,'Mit jelent magyarul?','comprehensive', 'átfogó','részleges','hiányos','rövid',0,1),
(1,0,2,'Mit jelent magyarul?','arbitrary', 'önkényes','jogos','szabályos','tervezett',0,1),
(1,0,2,'Mit jelent magyarul?','mitigate', 'enyhít','súlyosbít','okoz','kezd',0,1);

--------------------------------------------------------
-- ENGLISH – Grammar (1)
--------------------------------------------------------

-- === Beginner (0) ===
(1,1,0,'Egészítsd ki a mondatot!','She ___ happy.', 'are','is','be','am',1,1),
(1,1,0,'Egészítsd ki a mondatot!','I ___ a student.', 'is','are','am','be',2,1),
(1,1,0,'Egészítsd ki a mondatot!','They ___ football.', 'play','plays','playing','played',0,1),
(1,1,0,'Egészítsd ki a mondatot!','He ___ not like apples.', 'do','does','is','has',1,1),
(1,1,0,'Egészítsd ki a mondatot!','We ___ at home.', 'is','am','be','are',3,1),
(1,1,0,'Válaszd ki a helyes szót!','___ you speak English?', 'Do','Does','Is','Are',0,1),
(1,1,0,'Válaszd ki a helyes szót!','This is ___ book.', 'my','me','I','mine',0,1),
(1,1,0,'Egészítsd ki a mondatot!','Where ___ you from?', 'is','does','are','do',2,1),
(1,1,0,'Névelők','I have ___ cat.', 'an','the','two','a',3,1),
(1,1,0,'Ige ragozás','She ___ to school.', 'go','goes','going','gone',1,1),
(1,1,0,'Mutatószók','Look at ___ birds over there.', 'this','that','these','those',3,1),
(1,1,0,'Kérdőszavak','___ is your name?', 'Who','What','Where','Why',1,1),
(1,1,0,'Elöljárószók','The cat is ___ the table.', 'in','on','at','under',3,1),
(1,1,0,'Egészítsd ki a mondatot!','I ___ breakfast at 7.', 'eat','eats','eating','ate',0,1),
(1,1,0,'Egészítsd ki a mondatot!','He ___ swimming.', 'like','likes','liking','liked',1,1),

-- === Intermediate (1) ===
(1,1,1,'Válaszd ki a helyes alakot!','They ___ working.', 'is','are','be','am',1,1),
(1,1,1,'Múlt idő','I ___ yesterday.', 'work','working','worked','works',2,1),
(1,1,1,'Fokozás','She is ___ than me.', 'tall','taller','tallest','more tall',1,1),
(1,1,1,'Befejezett jelen','We have ___ to London.', 'be','been','being','was',1,1),
(1,1,1,'Segédigék','You ___ smoke here. It is forbidden.', 'must not','don''t have to','should','can',0,1),
(1,1,1,'Feltételes mód','If it rains, I ___ stay home.', 'would','will','am','was',1,1),
(1,1,1,'Folyamatos múlt','I was ___ TV when he called.', 'watch','watched','watching','watches',2,1),
(1,1,1,'Elöljárószók időben','I have lived here ___ 2010.', 'since','for','in','ago',0,1),
(1,1,1,'Gerund vs Infinitive','Do you enjoy ___?', 'read','to read','reading','reads',2,1),
(1,1,1,'Mennyiségjelzők','This car is ___ expensive.', 'to','too','two','enough',1,1),
(1,1,1,'Függő beszéd','He told me ___ quiet.', 'be','to be','being','was',1,1),
(1,1,1,'Vonzatok','I am interested ___ music.', 'on','at','in','with',2,1),
(1,1,1,'Udvarias kérés','___ I help you?', 'Must','Do','Can','Have',2,1),
(1,1,1,'Tagadás múltban','I didn''t ___ that.', 'know','knew','known','knows',0,1),
(1,1,1,'Szórend','She ___ already left.', 'has','have','is','was',0,1),

-- === Advanced (2) ===
(1,1,2,'Melyik a helyes?','He has ___ apples.', 'much','many','lot','lots',1,1),
(1,1,2,'Feltételes mód 2.','If I ___ you, I would go.', 'was','am','were','be',2,1),
(1,1,2,'Szenvedő szerkezet','The letter ___ written by John.', 'has','was','is','did',1,1),
(1,1,2,'Kívánság','I wish I ___ more time.', 'have','had','has','having',1,1),
(1,1,2,'Jövőbeli befejezett','By next year, I ___ finished.', 'will','will have','would have','had',1,1),
(1,1,2,'Függő kérdés','He asked me where ___ .', 'did I live','do I live','I lived','live I',2,1),
(1,1,2,'Kötőszavak','___ the rain, we went out.', 'Although','Despite','However','But',1,1),
(1,1,2,'Múltbeli tanács','I ___ have called him.', 'should','must','can','will',0,1),
(1,1,2,'Inverzió','No sooner had I arrived ___ he left.', 'than','when','that','then',0,1),
(1,1,2,'Szerkezet','It is high time we ___ .', 'go','went','gone','going',1,1),
(1,1,2,'Inverzió 2.','Seldom ___ seen such a thing.', 'I have','have I','I did','did I',1,1),
(1,1,2,'Szerkezet','I''d rather you ___ that.', 'don''t do','not do','didn''t do','won''t do',2,1),
(1,1,2,'Szokás','She is used to ___ early.', 'get up','getting up','got up','gets up',1,1),
(1,1,2,'Feltételes mód 3.','Had I known, I ___ helped.', 'would','would have','will have','had',1,1),
(1,1,2,'Műveltető','I had my car ___ .', 'repair','repairing','repaired','to repair',2,1),

--------------------------------------------------------
-- ENGLISH – Sentences (2)
--------------------------------------------------------

-- === Beginner (0) ===
(1,2,0,'Hogyan mondod angolul?','Mennyi az idő?', 'What time is it?','How time is it?','What is the time now?','What clock is?',0,1),
(1,2,0,'Hogyan mondod angolul?','Hogy vagy?', 'Who are you?','How are you?','Where are you?','How old are you?',1,1),
(1,2,0,'Hogyan mondod angolul?','Szia!', 'Goodbye!','Hello!','Please!','Sorry!',1,1),
(1,2,0,'Hogyan mondod angolul?','Jó reggelt!', 'Good morning!','Good night!','Good evening!','Good day!',0,1),
(1,2,0,'Hogyan mondod angolul?','Kérek egy kávét.', 'A coffee, please.','I like coffee.','Coffee is good.','No coffee.',0,1),
(1,2,0,'Hogyan mondod angolul?','Nem értem.', 'I understand.','I do not understand.','I know.','Yes please.',1,1),
(1,2,0,'Hogyan mondod angolul?','Bocsánat.', 'Sorry.','Thanks.','Please.','Good.',0,1),
(1,2,0,'Hogyan mondod angolul?','Köszönöm.', 'Please.','Thank you.','Sorry.','Excuse me.',1,1),
(1,2,0,'Hogyan mondod angolul?','Merre van a hotel?', 'Where is the hotel?','What is the hotel?','Hotel is where?','Who is hotel?',0,1),
(1,2,0,'Hogyan mondod angolul?','Magyar vagyok.', 'I am Hungarian.','I am Hungary.','Speak Hungarian.','Hungary is nice.',0,1),
(1,2,0,'Hogyan mondod angolul?','Nem tudom.', 'I know.','I don''t know.','I think.','Maybe.',1,1),
(1,2,0,'Hogyan mondod angolul?','Hány éves vagy?', 'How are you?','How old are you?','Who are you?','What age?',1,1),
(1,2,0,'Hogyan mondod angolul?','Szeretem a kutyákat.', 'I like dogs.','I hate dogs.','Dogs are bad.','I have a dog.',0,1),
(1,2,0,'Hogyan mondod angolul?','Viszlát!', 'Hello!','Goodbye!','Welcome!','Hi!',1,1),
(1,2,0,'Hogyan mondod angolul?','Igen, kérem.', 'No, thanks.','Yes, please.','Maybe.','Okay.',1,1),

-- === Intermediate (1) ===
(1,2,1,'Hogyan mondod angolul?','Hol dolgozol?', 'Where work you?','Where do you work?','Where are working you?','Where are you?',1,1),
(1,2,1,'Hogyan mondod angolul?','Szeretnék fizetni.', 'I would like to pay.','I pay now.','Money give.','Pay me.',0,1),
(1,2,1,'Hogyan mondod angolul?','Merre van az állomás?', 'Where is the station?','Station where?','Go to station.','What station?',0,1),
(1,2,1,'Hogyan mondod angolul?','Mit csináltál tegnap?', 'What did you do yesterday?','What do yesterday?','Yesterday what?','Did you yesterday?',0,1),
(1,2,1,'Hogyan mondod angolul?','Szeretek filmeket nézni.', 'I like watch movies.','I like watching movies.','Movies like me.','Watch movie good.',1,1),
(1,2,1,'Hogyan mondod angolul?','Tudsz nekem segíteni?', 'Can you help me?','Help me you?','Do you help?','Are you help?',0,1),
(1,2,1,'Hogyan mondod angolul?','Ez nagyon finom.', 'This is very delicious.','This is bad.','It is okay.','Not good.',0,1),
(1,2,1,'Hogyan mondod angolul?','Mennyibe kerül ez?', 'How much is this?','How many this?','What price?','Cost is what?',0,1),
(1,2,1,'Hogyan mondod angolul?','Fáj a fejem.', 'My head is pain.','I have a headache.','Head hurts.','Sick head.',1,1),
(1,2,1,'Hogyan mondod angolul?','Holnap ráérek.', 'I am free tomorrow.','Tomorrow busy.','I have time now.','Free day.',0,1),
(1,2,1,'Hogyan mondod angolul?','Milyen volt az út?', 'How was the trip?','Trip was good?','What trip?','Where did you go?',0,1),
(1,2,1,'Hogyan mondod angolul?','Elvesztettem a kulcsomat.', 'I lost my key.','Key is lost.','No key.','Where key?',0,1),
(1,2,1,'Hogyan mondod angolul?','Foglaljon helyet.', 'Sit down.','Have a seat.','Take place.','Seat please.',1,1),
(1,2,1,'Hogyan mondod angolul?','Ez nem az én hibám.', 'It is not my fault.','Not my problem.','No mistake.','I am good.',0,1),
(1,2,1,'Hogyan mondod angolul?','Jó ötletnek tűnik.', 'It looks good.','It seems like a good idea.','Good idea is.','Idea good.',1,1),

-- === Advanced (2) ===
(1,2,2,'Hogyan mondod angolul?','Miért késtél?', 'Why you late?','Why are you late?','Why late are you?','Why did late?',1,1),
(1,2,2,'Hogyan mondod angolul?','Attól tartok, nem értek egyet.', 'I am afraid I disagree.','I fear no agree.','Scared disagree.','Not agree sorry.',0,1),
(1,2,2,'Hogyan mondod angolul?','Bárcsak itt lennél.', 'I wish you were here.','I want you here.','Hope you here.','If you are here.',0,1),
(1,2,2,'Hogyan mondod angolul?','Minden a terv szerint halad.', 'All goes plan.','Everything is going according to plan.','Plan is good.','Going with plan.',1,1),
(1,2,2,'Hogyan mondod angolul?','Ne kertelj!', 'Do not garden!','Don''t beat around the bush!','Speak straight!','No bush!',1,1),
(1,2,2,'Hogyan mondod angolul?','Ez a csepp a pohárban.', 'This is the drop in glass.','That is the last straw.','Glass is full.','Last drop.',1,1),
(1,2,2,'Hogyan mondod angolul?','Kétségkívül igazad van.', 'You are undoubtedly right.','Maybe right.','Sure true.','No doubt yes.',0,1),
(1,2,2,'Hogyan mondod angolul?','Lényegében erről van szó.', 'This is the point.','That is essentially the point.','Basic thing.','Word is this.',1,1),
(1,2,2,'Hogyan mondod angolul?','Szeretnék panaszt tenni.', 'I want complain.','I would like to make a complaint.','Complaint do.','Make problem.',1,1),
(1,2,2,'Hogyan mondod angolul?','Alig várom a találkozást.', 'I hardly wait meeting.','I look forward to meeting you.','Wait for you.','Meeting is good.',1,1),
(1,2,2,'Hogyan mondod angolul?','Hogy őszinte legyek...', 'To be honest...','Be true...','Honestly say...','Real speak...',0,1),
(1,2,2,'Hogyan mondod angolul?','Valami nincs rendben.', 'Something is not okay.','Something is fishy.','Bad thing.','Not order.',1,1),
(1,2,2,'Hogyan mondod angolul?','Egy cipőben járunk.', 'We walk in one shoe.','We are in the same boat.','Same shoes.','Walking together.',1,1),
(1,2,2,'Hogyan mondod angolul?','Jobb félni, mint megijedni.', 'Better fear than scare.','Better safe than sorry.','Good safe.','Fear is good.',1,1),
(1,2,2,'Hogyan mondod angolul?','Ezt nem engedhetem meg magamnak.', 'I cannot allow myself.','I can''t afford this.','No money.','Not let me.',1,1);

--------------------------------------------------------
-- GERMAN (2) – Vocabulary (0)
--------------------------------------------------------

-- === Beginner (0) ===
(2,0,0,'Mit jelent magyarul?','das Haus', 'ház','kert','szoba','város',0,1),
(2,0,0,'Mit jelent magyarul?','der Hund', 'kutya','macska','egér','ló',0,1),
(2,0,0,'Mit jelent magyarul?','die Katze', 'kutya','madár','hal','macska',3,1),
(2,0,0,'Mit jelent magyarul?','rot', 'piros','kék','zöld','sárga',0,1),
(2,0,0,'Mit jelent magyarul?','danke', 'szia','köszönöm','kérem','bocsánat',1,1),
(2,0,0,'Mit jelent magyarul?','die Mutter', 'apa','anya','nagyi','testvér',1,1),
(2,0,0,'Mit jelent magyarul?','das Wasser', 'tűz','föld','levegő','víz',3,1),
(2,0,0,'Mit jelent magyarul?','eins', 'egy','kettő','három','négy',0,1),
(2,0,0,'Mit jelent magyarul?','der Apfel', 'körte','szilva','alma','banán',2,1),
(2,0,0,'Mit jelent magyarul?','das Auto', 'autó','busz','vonat','hajó',0,1),
(2,0,0,'Mit jelent magyarul?','die Schule', 'mozi','iskola','bolt','park',1,1),
(2,0,0,'Mit jelent magyarul?','brot', 'tej','sajt','vaj','kenyér',3,1),
(2,0,0,'Mit jelent magyarul?','heute', 'tegnap','ma','holnap','most',1,1),
(2,0,0,'Mit jelent magyarul?','groß', 'nagy','kicsi','gyors','lassú',0,1),
(2,0,0,'Mit jelent magyarul?','die Milch', 'sör','bor','víz','tej',3,1),

-- === Intermediate (1) ===
(2,0,1,'Mit jelent magyarul?','der Freund', 'testvér','barát','szomszéd','ellenség',1,1),
(2,0,1,'Mit jelent magyarul?','der Wald', 'mező','erdő','hegy','folyó',1,1),
(2,0,1,'Mit jelent magyarul?','die Reise', 'utazás','munka','pihenés','tanulás',0,1),
(2,0,1,'Mit jelent magyarul?','gefährlich', 'biztonságos','veszélyes','könnyű','nehéz',1,1),
(2,0,1,'Mit jelent magyarul?','die Entscheidung', 'kérdés','válasz','döntés','hiba',2,1),
(2,0,1,'Mit jelent magyarul?','der Erfolg', 'siker','bukás','próba','feladat',0,1),
(2,0,1,'Mit jelent magyarul?','wichtig', 'fontos','felesleges','érdekes','unalmas',0,1),
(2,0,1,'Mit jelent magyarul?','die Freiheit', 'börtön','törvény','szabadság','jog',2,1),
(2,0,1,'Mit jelent magyarul?','der Brücke', 'út','híd','ház','kapu',1,1), -- die Brücke actually, but generic noun check
(2,0,1,'Mit jelent magyarul?','vielleicht', 'biztosan','talán','soha','mindig',1,1),
(2,0,1,'Mit jelent magyarul?','die Erfahrung', 'tudás','könyv','tapasztalat','iskola',2,1),
(2,0,1,'Mit jelent magyarul?','sofort', 'később','most','azonnal','soha',2,1),
(2,0,1,'Mit jelent magyarul?','die Lösung', 'probléma','megoldás','terv','ok',1,1),
(2,0,1,'Mit jelent magyarul?','einfach', 'bonyolult','egyszerű','nehéz','szép',1,1),
(2,0,1,'Mit jelent magyarul?','der Fehler', 'hiba','javítás','siker','eredmény',0,1),

-- === Advanced (2) ===
(2,0,2,'Mit jelent magyarul?','die Umgebung', 'környezet','hangulat','ország','időjárás',0,1),
(2,0,2,'Mit jelent magyarul?','die Entwicklung', 'fejlődés','romlás','állapot','változás',0,1),
(2,0,2,'Mit jelent magyarul?','nachhaltig', 'fenntartható','ideiglenes','káros','drága',0,1),
(2,0,2,'Mit jelent magyarul?','die Folge', 'ok','kezdet','következmény','cél',2,1),
(2,0,2,'Mit jelent magyarul?','der Zufall', 'terv','véletlen','szándék','sors',1,1),
(2,0,2,'Mit jelent magyarul?','unvermeidlich', 'elkerülhetetlen','lehetséges','bizonytalan','kizárt',0,1),
(2,0,2,'Mit jelent magyarul?','der Widerspruch', 'egyetértés','ellentmondás','hasonlóság','igazság',1,1),
(2,0,2,'Mit jelent magyarul?','zweideutig', 'egyértelmű','kétértelmű','világos','egyszerű',1,1),
(2,0,2,'Mit jelent magyarul?','veraltet', 'modern','új','elavult','friss',2,1),
(2,0,2,'Mit jelent magyarul?','erheblich', 'jelentős','apró','kevés','gyenge',0,1),
(2,0,2,'Mit jelent magyarul?','gleichzeitig', 'külön','egyszerre','később','előbb',1,1),
(2,0,2,'Mit jelent magyarul?','umfassend', 'részleges','hiányos','átfogó','rövid',2,1),
(2,0,2,'Mit jelent magyarul?','willkürlich', 'önkényes','jogos','szabályos','tervezett',0,1),
(2,0,2,'Mit jelent magyarul?','die Bedingung', 'feltétel','ok','eredmény','akadály',0,1),
(2,0,2,'Mit jelent magyarul?','überzeugen', 'meggyőz','kételkedik','hazudik','kérdez',0,1),


--------------------------------------------------------
-- GERMAN – Grammar (1)
--------------------------------------------------------

-- === Beginner (0) ===
(2,1,0,'Válaszd ki a helyes névelőt!','___ Auto (semleges)', 'Der','Die','Das','Den',2,1),
(2,1,0,'Válaszd ki a helyes névelőt!','___ Mann (hímnem)', 'Der','Die','Das','Den',0,1),
(2,1,0,'Válaszd ki a helyes névelőt!','___ Frau (nőnem)', 'Der','Die','Das','Den',1,1),
(2,1,0,'Igeragozás','Ich ___ (sein)', 'bist','bin','ist','sind',1,1),
(2,1,0,'Igeragozás','Du ___ (haben)', 'habe','hast','hat','haben',1,1),
(2,1,0,'Igeragozás','Wir ___ (gehen)', 'gehe','gehst','gehen','geht',2,1),
(2,1,0,'Többesszám','Ein Apfel, zwei ___ .', 'Apfel','Äpfel','Apfels','Äpfeln',1,1),
(2,1,0,'Válaszd ki a helyes névelőt!','___ Tisch (hímnem)', 'Der','Die','Das','Ein',0,1),
(2,1,0,'Tagadás','Das ist ___ Buch.', 'nein','nicht','kein','nichts',2,1),
(2,1,0,'Igeragozás','Er ___ (kommen)', 'komme','kommst','kommt','kommen',2,1),
(2,1,0,'Személyes névmás','___ (én) heiße Peter.', 'Du','Er','Ich','Wir',2,1),
(2,1,0,'Szórend','Ich ___ Musik.', 'mag','möge','magen','möglich',0,1),
(2,1,0,'Elöljárószó','Ich komme ___ Ungarn.', 'aus','in','bei','zu',0,1),
(2,1,0,'Kérdőszó','___ bist du?', 'Was','Wer','Wo','Wie',1,1),
(2,1,0,'Birtokos','Das ist ___ (enyém) Haus.', 'mein','dein','sein','ihr',0,1),

-- === Intermediate (1) ===
(2,1,1,'Egészítsd ki!','Ich ___ müde.', 'bist','sind','bin','seid',2,1),
(2,1,1,'Múlt idő (Perfekt)','Ich habe ___ .', 'gelernt','lernen','lernte','lernt',0,1),
(2,1,1,'Módbeli segédige','Du ___ das machen. (müssen)', 'muss','musst','müssen','müsst',1,1),
(2,1,1,'Névelőragozás (Tárgyeset)','Ich sehe ___ Hund (der).', 'der','dem','den','das',2,1),
(2,1,1,'Elöljárószó (Dativ)','Ich gehe mit ___ Freund.', 'der','dem','den','des',1,1),
(2,1,1,'Kötőszó','Ich lerne Deutsch, ___ ich arbeiten will.', 'weil','denn','aber','und',0,1),
(2,1,1,'Múlt idő (Präteritum)','Gestern ___ ich im Kino.', 'bin','war','wäre','wurde',1,1),
(2,1,1,'Melléknév ragozás','Das ist ein ___ Auto.', 'schönes','schöne','schön','schönen',0,1),
(2,1,1,'Elöljárószó','Das Geschenk ist ___ dich.', 'für','mit','zu','bei',0,1),
(2,1,1,'Vonzat','Ich warte ___ den Bus.', 'auf','an','in','zu',0,1),
(2,1,1,'Felszólító mód','___ Sie mir bitte!', 'Helfen','Hilf','Helft','Hilft',0,1),
(2,1,1,'Kérdő szórend','___ du heute Zeit?', 'Hast','Habe','Haben','Hat',0,1),
(2,1,1,'Visszaható ige','Ich wasche ___ .', 'mich','dich','sich','uns',0,1),
(2,1,1,'Jövő idő','Wir ___ morgen reisen.', 'werden','wird','werde','wurden',0,1),
(2,1,1,'Tagadás','Ich habe das ___ gemacht.', 'nicht','kein','nein','nie',0,1),

-- === Advanced (2) ===
(2,1,2,'Melyik a helyes múlt idő?','Er ___ gegangen.', 'habe','hat','ist','seid',2,1),
(2,1,2,'Feltételes mód (Konj. II)','Wenn ich Zeit ___, würde ich kommen.', 'habe','hätte','hatte','hab',1,1),
(2,1,2,'Szenvedő szerkezet (Passiv)','Das Haus ___ gebaut.', 'wird','werdet','hat','ist',0,1),
(2,1,2,'Melléknév ragozás (Gyenge)','Mit dem ___ Auto.', 'neuen','neue','neues','neuem',0,1),
(2,1,2,'Genitiv','Das Auto ___ Vaters.', 'der','des','dem','den',1,1),
(2,1,2,'Vonatkozó névmás','Der Mann, ___ ich sehe.', 'der','dem','den','dessen',2,1),
(2,1,2,'Kötőszó','___ es regnet, gehe ich raus.', 'Obwohl','Weil','Dass','Wenn',0,1),
(2,1,2,'Befejezett múlt (Plusquamperfekt)','Nachdem er ___ ___, ging er schlafen.', 'gegessen hatte','gegessen hat','essen hatte','gegessen war',0,1),
(2,1,2,'Igei vonzat','Ich interessiere mich ___ Musik.', 'für','an','auf','über',0,1),
(2,1,2,'Főnévvé képzés','Das ___ ist verboten.', 'Rauchen','rauchen','Rauch','rauchend',0,1),
(2,1,2,'Módbeli (Múlt)','Er ___ das nicht tun sollen.', 'hätte','habe','hat','hatte',0,1),
(2,1,2,'Passzív (Múlt)','Der Brief ___ geschrieben.', 'wurde','wurd','worden','war',0,1),
(2,1,2,'Kötőszó','Je schneller, ___ besser.', 'desto','umso','als','wie',0,1),
(2,1,2,'Kifejezés','Es kommt ___ an.', 'darauf','daran','dabei','darüber',0,1),
(2,1,2,'Melléknévi igenév','Das ___ Kind spielt.', 'lachende','lachend','lacht','lachen',0,1),

--------------------------------------------------------
-- GERMAN – Sentences (2)
--------------------------------------------------------

-- === Beginner (0) ===
(2,2,0,'Hogyan mondod németül?','Hol laksz?', 'Wo wohnst du?','Wo du wohnst?','Wo wohnen du?','Wo wohnst?',0,1),
(2,2,0,'Hogyan mondod németül?','Hogy vagy?', 'Wie geht es dir?','Wer bist du?','Wo bist du?','Was machst du?',0,1),
(2,2,0,'Hogyan mondod németül?','Jó reggelt!', 'Guten Morgen!','Gute Nacht!','Guten Tag!','Hallo!',0,1),
(2,2,0,'Hogyan mondod németül?','Köszönöm.', 'Bitte.','Danke.','Entschuldigung.','Hallo.',1,1),
(2,2,0,'Hogyan mondod németül?','Nem értem.', 'Ich verstehe nicht.','Ich weiß nicht.','Ich kenne nicht.','Nein danke.',0,1),
(2,2,0,'Hogyan mondod németül?','Szia!', 'Tschüss!','Bitte!','Danke!','Gut!',0,1),
(2,2,0,'Hogyan mondod németül?','Kérek egy kávét.', 'Einen Kaffee, bitte.','Kaffee haben.','Ich mag Kaffee.','Kaffee gut.',0,1),
(2,2,0,'Hogyan mondod németül?','Bocsánat.', 'Entschuldigung.','Danke.','Bitte.','Gut.',0,1),
(2,2,0,'Hogyan mondod németül?','Igen.', 'Ja.','Nein.','Vielleicht.','Doch.',0,1),
(2,2,0,'Hogyan mondod németül?','Nem.', 'Nein.','Ja.','Doch.','Bitte.',0,1),
(2,2,0,'Hogyan mondod németül?','Hogy hívnak?', 'Wie heißt du?','Wer bist du?','Wo bist du?','Was ist das?',0,1),
(2,2,0,'Hogyan mondod németül?','Magyar vagyok.', 'Ich bin Ungar.','Ich bin Deutscher.','Ungarn ist schön.','Spreche Ungarisch.',0,1),
(2,2,0,'Hogyan mondod németül?','Nem tudom.', 'Ich weiß nicht.','Ich verstehe nicht.','Keine Ahnung.','Vielleicht.',0,1),
(2,2,0,'Hogyan mondod németül?','Viszlát!', 'Auf Wiedersehen!','Hallo!','Guten Tag!','Morgen!',0,1),
(2,2,0,'Hogyan mondod németül?','Éhes vagyok.', 'Ich habe Hunger.','Ich habe Durst.','Ich bin müde.','Ich bin satt.',0,1),

-- === Intermediate (1) ===
(2,2,1,'Hogyan mondod németül?','Mikor jössz?', 'Wann kommst du?','Wann du kommst?','Wann kommen du?','Wann bist du?',0,1),
(2,2,1,'Hogyan mondod németül?','Szeretnék fizetni.', 'Ich möchte bezahlen.','Ich will Geld.','Zahlen bitte.','Geld geben.',0,1),
(2,2,1,'Hogyan mondod németül?','Hol van az állomás?', 'Wo ist der Bahnhof?','Wo Bahnhof?','Bahnhof wo ist?','Ist Bahnhof dort?',0,1),
(2,2,1,'Hogyan mondod németül?','Ez túl drága.', 'Das ist zu teuer.','Das ist billig.','Das ist gut.','Viel Geld.',0,1),
(2,2,1,'Hogyan mondod németül?','Tudsz segíteni?', 'Kannst du mir helfen?','Hilfst du?','Helfen bitte?','Kannst helfen?',0,1),
(2,2,1,'Hogyan mondod németül?','Beszélsz németül?', 'Sprichst du Deutsch?','Sprechen Deutsch?','Deutsch du?','Bist du Deutsch?',0,1),
(2,2,1,'Hogyan mondod németül?','Mit csináltál tegnap?', 'Was hast du gestern gemacht?','Was machtest gestern?','Gestern was?','Hast du gestern?',0,1),
(2,2,1,'Hogyan mondod németül?','Sajnálom, nem érek rá.', 'Leider habe ich keine Zeit.','Keine Zeit.','Ich bin frei.','Entschuldigung.',0,1),
(2,2,1,'Hogyan mondod németül?','Merre van a központ?', 'Wo ist das Zentrum?','Zentrum wo?','Wohin Zentrum?','Das ist Zentrum.',0,1),
(2,2,1,'Hogyan mondod németül?','Jó ötlet.', 'Gute Idee.','Schlechte Idee.','Keine Idee.','Idee gut.',0,1),
(2,2,1,'Hogyan mondod németül?','Fáj a fejem.', 'Ich habe Kopfschmerzen.','Mein Kopf ist schlecht.','Kopf weh.','Kranker Kopf.',0,1),
(2,2,1,'Hogyan mondod németül?','Mennyibe kerül?', 'Wie viel kostet das?','Was kostet?','Wie viel Geld?','Teuer ist?',0,1),
(2,2,1,'Hogyan mondod németül?','Holnap találkozunk.', 'Bis morgen.','Hallo morgen.','Gestern sehen.','Morgen kommen.',0,1),
(2,2,1,'Hogyan mondod németül?','Ez nagyon finom.', 'Das ist sehr lecker.','Das ist schlecht.','Nicht gut.','Essen gut.',0,1),
(2,2,1,'Hogyan mondod németül?','Mit dolgozol?', 'Was bist du von Beruf?','Was arbeitest?','Wo Arbeit?','Beruf was?',0,1),

-- === Advanced (2) ===
(2,2,2,'Hogyan mondod németül?','Mit csinálsz?', 'Was machst du?','Was du machst?','Was bist du machen?','Machst was du?',0,1),
(2,2,2,'Hogyan mondod németül?','Attól függ.', 'Es kommt darauf an.','Das hängt.','Vielleicht so.','Davon abhängig.',0,1),
(2,2,2,'Hogyan mondod németül?','Egyetértek veled.', 'Ich stimme dir zu.','Ich bin mit dir.','Gleiche Meinung.','Du hast Recht.',0,1),
(2,2,2,'Hogyan mondod németül?','Ez nekem kínai.', 'Ich verstehe nur Bahnhof.','Das ist Chinesisch.','Ich verstehe nicht.','Keine Ahnung.',0,1), -- Idiom
(2,2,2,'Hogyan mondod németül?','Ha lett volna időm, elmentem volna.', 'Wenn ich Zeit gehabt hätte, wäre ich gegangen.','Wenn Zeit, dann gehen.','Hätte Zeit, wäre gegangen.','Zeit haben, gehen.',0,1),
(2,2,2,'Hogyan mondod németül?','Kétségkívül igazad van.', 'Du hast zweifellos Recht.','Sicher Recht.','Ohne Zweifel.','Recht haben.',0,1),
(2,2,2,'Hogyan mondod németül?','Ez a legjobb megoldás.', 'Das ist die beste Lösung.','Gute Lösung.','Besser Weg.','Lösung ist gut.',0,1),
(2,2,2,'Hogyan mondod németül?','Szeretnék panaszt tenni.', 'Ich möchte mich beschweren.','Beschwerde machen.','Reklamation bitte.','Problem haben.',0,1),
(2,2,2,'Hogyan mondod németül?','Minden a terv szerint halad.', 'Alles läuft nach Plan.','Plan ist gut.','Gehen mit Plan.','Alles gut.',0,1),
(2,2,2,'Hogyan mondod németül?','Jobb félni, mint megijedni.', 'Vorsicht ist besser als Nachsicht.','Besser Angst als Schreck.','Angst ist gut.','Nicht erschrecken.',0,1), 
(2,2,2,'Hogyan mondod németül?','Ne csinálj bolhából elefántot!', 'Mach aus einer Mücke keinen Elefanten!','Kein Elefant bitte.','Mücke und Elefant.','Nicht übertreiben.',0,1),
(2,2,2,'Hogyan mondod németül?','Lényegében erről van szó.', 'Im Grunde geht es darum.','Das ist der Punkt.','Wichtig ist das.','Darüber sprechen.',0,1),
(2,2,2,'Hogyan mondod németül?','Alig várom.', 'Ich kann es kaum erwarten.','Warten schwer.','Ich warte nicht.','Schnell bitte.',0,1),
(2,2,2,'Hogyan mondod németül?','Meggyőződésem, hogy sikerülni fog.', 'Ich bin überzeugt, dass es klappt.','Sicher Erfolg.','Glaube ja.','Hoffentlich.',0,1),
(2,2,2,'Hogyan mondod németül?','Két legyet egy csapásra.', 'Zwei Fliegen mit einer Klappe schlagen.','Zwei Vögel ein Stein.','Doppelter Erfolg.','Fliegen schlagen.',0,1);

--------------------------------------------------------
-- RUSSIAN (3) – Vocabulary (0)
--------------------------------------------------------

-- === Beginner (0) ===
(3,0,0,'Mit jelent magyarul?','мама', 'anya','apa','barát','testvér',0,1),
(3,0,0,'Mit jelent magyarul?','папа', 'anya','apa','nagypapa','nagymama',1,1),
(3,0,0,'Mit jelent magyarul?','дом', 'ház','lakás','szoba','város',0,1),
(3,0,0,'Mit jelent magyarul?','вода', 'tűz','föld','levegő','víz',3,1),
(3,0,0,'Mit jelent magyarul?','кот', 'kutya','macska','madár','egér',1,1),
(3,0,0,'Mit jelent magyarul?','собака', 'kutya','ló','tehén','farkas',0,1),
(3,0,0,'Mit jelent magyarul?','хлеб', 'víz','tej','sör','kenyér',3,1),
(3,0,0,'Mit jelent magyarul?','нет', 'igen','nem','talán','persze',1,1),
(3,0,0,'Mit jelent magyarul?','да', 'nem','igen','soha','most',1,1),
(3,0,0,'Mit jelent magyarul?','спасибо', 'szia','viszlát','köszönöm','kérem',2,1),
(3,0,0,'Mit jelent magyarul?','школа', 'iskola','egyetem','munka','piac',0,1),
(3,0,0,'Mit jelent magyarul?','стол', 'szék','ágy','asztal','szekrény',2,1),
(3,0,0,'Mit jelent magyarul?','город', 'falu','város','ország','világ',1,1),
(3,0,0,'Mit jelent magyarul?','хорошо', 'rossz','jó','kicsi','nagy',1,1),
(3,0,0,'Mit jelent magyarul?','один', 'egy','kettő','három','nulla',0,1),

-- === Intermediate (1) ===
(3,0,1,'Mit jelent magyarul?','друг', 'ellenség','barát','szomszéd','testvér',1,1),
(3,0,1,'Mit jelent magyarul?','работа', 'pihenés','utazás','munka','tanulás',2,1),
(3,0,1,'Mit jelent magyarul?','время', 'idő','tér','hely','perc',0,1),
(3,0,1,'Mit jelent magyarul?','думать', 'beszélni','gondolni','írni','olvasni',1,1),
(3,0,1,'Mit jelent magyarul?','деньги', 'pénz','arany','bank','hitel',0,1),
(3,0,1,'Mit jelent magyarul?','знать', 'tudni','kérdezni','válaszolni','érteni',0,1),
(3,0,1,'Mit jelent magyarul?','красивый', 'csúnya','szép','okos','buta',1,1),
(3,0,1,'Mit jelent magyarul?','быстро', 'lassan','gyorsan','korán','későn',1,1),
(3,0,1,'Mit jelent magyarul?','семья', 'barátok','munkahely','család','iskola',2,1),
(3,0,1,'Mit jelent magyarul?','улица', 'tér','ház','út','utca',3,1),
(3,0,1,'Mit jelent magyarul?','вопрос', 'válasz','kérdés','feladat','hiba',1,1),
(3,0,1,'Mit jelent magyarul?','мир', 'háború','béke / világ','harc','csend',1,1),
(3,0,1,'Mit jelent magyarul?','понимать', 'érteni','hallani','látni','érezni',0,1),
(3,0,1,'Mit jelent magyarul?','любовь', 'gyűlölet','barátság','szerelem','csalódás',2,1),
(3,0,1,'Mit jelent magyarul?','жить', 'halni','élni','lakni','menni',1,1),

-- === Advanced (2) ===
(3,0,2,'Mit jelent magyarul?','окружение', 'környezet','barát','időjárás','ország',0,1),
(3,0,2,'Mit jelent magyarul?','развитие', 'fejlődés','hanyatlás','állandóság','szünet',0,1),
(3,0,2,'Mit jelent magyarul?','возможность', 'lehetőség','akadály','tilalom','parancs',0,1),
(3,0,2,'Mit jelent magyarul?','отношения', 'kapcsolatok','távolság','idegenség','magány',0,1),
(3,0,2,'Mit jelent magyarul?','впечатление', 'csalódás','benyomás','emlék','felejtés',1,1),
(3,0,2,'Mit jelent magyarul?','правительство', 'kormány','nép','elnök','törvény',0,1),
(3,0,2,'Mit jelent magyarul?','безопасность', 'veszély','biztonság','kockázat','félelem',1,1),
(3,0,2,'Mit jelent magyarul?','ответственность', 'felelősség','szabadság','jog','kötelesség',0,1),
(3,0,2,'Mit jelent magyarul?','достижение', 'kudarc','próba','eredmény / vívmány','veszteség',2,1),
(3,0,2,'Mit jelent magyarul?','образование', 'oktatás','nevelés','tudás','iskola',0,1),
(3,0,2,'Mit jelent magyarul?','существенный', 'lényeges','apró','kevés','felesleges',0,1),
(3,0,2,'Mit jelent magyarul?','последствие', 'ok','kezdet','következmény','terv',2,1),
(3,0,2,'Mit jelent magyarul?','уверенность', 'bizonytalanság','kétség','magabiztosság','félelem',2,1),
(3,0,2,'Mit jelent magyarul?','искусство', 'tudomány','művészet','sport','technika',1,1),
(3,0,2,'Mit jelent magyarul?','свобода', 'rabság','börtön','szabadság','korlát',2,1),

--------------------------------------------------------
-- RUSSIAN – Grammar (1)
--------------------------------------------------------

-- === Beginner (0) ===
(3,1,0,'Egészítsd ki!','Я ___ дома.', 'есть','буду','- (nincs ige)','иду',2,1),
(3,1,0,'Személyes névmás','___ (én) читаю.', 'Ты','Я','Он','Мы',1,1),
(3,1,0,'Hímnem','Это мой ___ .', 'стол','книга','окно','мама',0,1),
(3,1,0,'Nőnem','Это моя ___ .', 'дом','стол','машина','окно',2,1),
(3,1,0,'Igeragozás','Ты ___ (dolgozol).', 'работаю','работает','работаешь','работаем',2,1),
(3,1,0,'Birtoklás','У меня ___ собака.', 'есть','быть','иметь','нет',0,1),
(3,1,0,'Többesszám','Один стол, два ___ .', 'стол','столы','стола','столов',2,1), 
(3,1,0,'Köszönés','___ (Jó) утро!', 'Доброе','Добрый','Добрая','Добрые',0,1),
(3,1,0,'Tagadás','Я ___ понимаю.', 'нет','не','ни','без',1,1),
(3,1,0,'Hol?','Я ___ школе.', 'на','у','в','из',2,1),
(3,1,0,'Névmás (Tárgy)','Я люблю ___ (téged).', 'ты','тебя','тебе','тобой',1,1),
(3,1,0,'Kérdőszó','___ это?', 'Кто','Что','Где','Как',1,1), -- What is this?
(3,1,0,'Jelen idő','Мы ___ по-русски.', 'говорим','говорит','говорю','говорят',0,1),
(3,1,0,'Ige','Она ___ (alszik).', 'спишь','сплю','спит','спят',2,1),
(3,1,0,'Semleges nem','Это моё ___ .', 'окно','стол','книга','дом',0,1),

-- === Intermediate (1) ===
(3,1,1,'Válaszd ki a helyes alakot!','Он ___ читать.', 'любить','любит','любишь','люблю',1,1),
(3,1,1,'Múlt idő (Hímnem)','Вчера я ___ (dolgoztam).', 'работал','работала','работали','работать',0,1),
(3,1,1,'Birtokos eset','У меня нет ___ (autó).', 'машина','машину','машины','машине',2,1),
(3,1,1,'Tárgyeset','Я вижу ___ (Barátnő).', 'подруга','подругу','подруги','подруге',1,1),
(3,1,1,'Mozgás','Я ___ в школу (gyalog, most).', 'иду','хожу','пошёл','езжу',0,1),
(3,1,1,'Múlt idő (Nőnem)','Анна ___ дома.', 'был','была','было','были',1,1),
(3,1,1,'Jövő idő','Завтра я ___ работать.', 'буду','был','есть','стану',0,1),
(3,1,1,'Eszközhatározó','Я пишу ___ (tollal).', 'ручка','ручки','ручку','ручкой',3,1),
(3,1,1,'Részes eset','Я даю книгу ___ (Péternek).', 'Пётр','Петра','Петру','Петром',2,1),
(3,1,1,'Elöljárós eset','Я думаю о ___ (munka).', 'работу','работы','работе','работой',2,1),
(3,1,1,'Módbeli segédige','Я ___ (kell) идти.', 'должен','нужно','можно','хочу',0,1),
(3,1,1,'Felszólító mód','___ (mondd) мне!', 'Скажи','Сказать','Скажет','Сказал',0,1),
(3,1,1,'Kérdőszó','___ ты живёшь? (Hol)', 'Куда','Где','Откуда','Зачем',1,1),
(3,1,1,'Sorszámnév','___ (Első) урок.', 'Один','Первый','Раз','Единый',1,1),
(3,1,1,'Igekötő','Я ___ (megcsináltam) это.', 'делал','сделал','делать','сделать',1,1),

-- === Advanced (2) ===
(3,1,2,'Melyik a helyes?','Мы ___ в школу (most megyünk).', 'идёшь','идут','идём','идёт',2,1),
(3,1,2,'Feltételes mód','Если бы я знал, я бы ___ .', 'сказал','скажу','сказать','сказал бы',0,1), 
(3,1,2,'Folyamatos vs Befejezett','Вчера я целый день ___ (olvastam).', 'прочитал','читал','читаю','прочитаю',1,1),
(3,1,2,'Melléknévi igenév (Aktív)','Человек, ___ (olvasó) книгу.', 'читающий','читавший','читаемый','читая',0,1),
(3,1,2,'Szenvedő szerkezet','Книга ___ (írta) автором.', 'написана','написал','напишет','написала',0,1),
(3,1,2,'Határozói igenév','___ (Olvasva) книгу, он уснул.', 'Читающий','Читая','Читал','Прочитав',1,1),
(3,1,2,'Mozgás igék','Каждый день я ___ на работу.', 'иду','хожу','пошёл','пойду',1,1),
(3,1,2,'Vonzat','Я боюсь ___ (kutyák).', 'собаки','собак','собакам','собаками',1,1),
(3,1,2,'Tagadó névmás','Я ___ (semmit) не знаю.', 'ничего','что-то','нечто','кое-что',0,1),
(3,1,2,'Fokozás','Эта книга ___ (érdekesebb), чем та.', 'интереснее','интересный','самый интересный','более интересный',0,1),
(3,1,2,'Időhatározó','___ (Két) года.', 'Два','Две','Двое','Второй',0,1),
(3,1,2,'Kötőszó','Я хочу, ___ ты пришёл.', 'что','чтобы','как','где',1,1),
(3,1,2,'Számnevek ragozása','С ___ (öt) друзьями.', 'пять','пятью','пяти','пятерых',1,1),
(3,1,2,'Visszaható ige','Они ___ (találkoztak).', 'встретили','встретились','встречают','встречаются',1,1),
(3,1,2,'Személytelen szerkezet','Мне ___ (hidegem van/fázom).', 'холодно','холодный','холод','холодна',0,1),

--------------------------------------------------------
-- RUSSIAN – Sentences (2)
--------------------------------------------------------

-- === Beginner (0) ===
(3,2,0,'Hogyan mondod oroszul?','Hogy vagy?', 'Как ты? / Как дела?','Кто ты?','Где ты?','Какой ты?',0,1),
(3,2,0,'Hogyan mondod oroszul?','Jó reggelt!', 'Доброе утро!','Добрый день!','Добрый вечер!','Спокойной ночи!',0,1),
(3,2,0,'Hogyan mondod oroszul?','Nem értem.', 'Я не понимаю.','Я знаю.','Я понимаю.','Конечно.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Hogy hívnak?', 'Как тебя зовут?','Кто ты?','Где ты живёшь?','Что это?',0,1),
(3,2,0,'Hogyan mondod oroszul?','Magyar vagyok.', 'Я венгр.','Я русский.','Венгрия красивая.','Ты венгр.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Köszönöm.', 'Пожалуйста.','Спасибо.','Извини.','Привет.',1,1),
(3,2,0,'Hogyan mondod oroszul?','Kérek egy kávét.', 'Один кофе, пожалуйста.','Я люблю кофе.','Кофе хороший.','Нет кофе.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Hol van a metró?', 'Где метро?','Что метро?','Метро там?','Кто метро?',0,1),
(3,2,0,'Hogyan mondod oroszul?','Szia! (köszönés)', 'Привет!','Пока!','До свидания!','Спокойной ночи!',0,1),
(3,2,0,'Hogyan mondod oroszul?','Viszlát!', 'Привет!','Пока! (Baráti) / До свидания!','Здравствуй!','Доброе утро!',1,1),
(3,2,0,'Hogyan mondod oroszul?','Bocsánat.', 'Извините.','Спасибо.','Пожалуйста.','Хорошо.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Nem tudom.', 'Я не знаю.','Я знаю.','Я думаю.','Может быть.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Igen.', 'Да.','Нет.','Не знаю.','Может.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Nem.', 'Нет.','Да.','Конечно.','Ладно.',0,1),
(3,2,0,'Hogyan mondod oroszul?','Éhes vagyok.', 'Я голоден.','Я устал.','Я рад.','Я здесь.',0,1),

-- === Intermediate (1) ===
(3,2,1,'Hogyan mondod oroszul?','Hol élsz?', 'Где ты живёшь?','Где живёшь?','Ты где живёшь?','Где ты есть?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Szeretek utazni.', 'Я люблю путешествовать.','Я хочу спать.','Я иду домой.','Путешествие это хорошо.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Mit csináltál tegnap?', 'Что ты делал вчера?','Что делаешь?','Где был вчера?','Когда ты делал?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Szeretnék fizetni.', 'Я хочу заплатить.','Где деньги?','Платить нет.','Давай деньги.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Ez túl drága.', 'Это слишком дорого.','Это дёшево.','Это хорошо.','Сколько стоит?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Tudsz segíteni?', 'Ты можешь помочь?','Помоги мне!','Что делаешь?','Где помощь?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Beszélsz angolul?', 'Ты говоришь по-английски?','Ты знаешь английский?','Английский язык?','Где английский?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Fáj a fejem.', 'У меня болит голова.','Голова нет.','Я больной.','Голова большая.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Hány óra van?', 'Сколько времени?','Где часы?','Который час?','Часы есть?',2,1), 
(3,2,1,'Hogyan mondod oroszul?','Holnap találkozunk.', 'До завтра. / Увидимся завтра.','Вчера был.','Сегодня нет.','Завтра приду.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Minden rendben.', 'Всё в порядке.','Всё плохо.','Нет проблем.','Что случилось?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Sajnálom, nem érek rá.', 'Извини, я занят.','Я свободен.','У меня есть время.','Пошли.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Mit dolgozol?', 'Кем ты работаешь?','Что работаешь?','Где работа?','Работа есть?',0,1),
(3,2,1,'Hogyan mondod oroszul?','Nagyon finom.', 'Очень вкусно.','Очень плохо.','Не вкусно.','Красиво.',0,1),
(3,2,1,'Hogyan mondod oroszul?','Hová mész?', 'Куда ты идёшь?','Где ты идёшь?','Откуда ты?','Зачем ты?',0,1),

-- === Advanced (2) ===
(3,2,2,'Hogyan mondod oroszul?','Miért jöttél?', 'Почему ты пришёл?','Зачем пришёл?','Когда пришёл?','Где пришёл?',0,1),
(3,2,2,'Hogyan mondod oroszul?','Attól függ.', 'Зависит от обстоятельств. / Это зависит.','Не знаю.','Может быть.','Конечно.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Egyetértek veled.', 'Я согласен с тобой.','Я против.','Ты прав.','Нет.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Hogy őszinte legyek...', 'Честно говоря...','Быть честным...','Правда...','Я говорю...',0,1),
(3,2,2,'Hogyan mondod oroszul?','Semmi közöd hozzá.', 'Это не твоё дело.','Не важно.','Ты знаешь.','Моё дело.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Meggyőződésem, hogy...', 'Я убеждён, что...','Я думаю...','Кажется...','Может...',0,1),
(3,2,2,'Hogyan mondod oroszul?','Kétségkívül.', 'Несомненно / Без сомнения.','Может быть.','Вряд ли.','Никогда.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Ez a legjobb megoldás.', 'Это лучшее решение.','Это плохо.','Решение нет.','Хорошо.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Jobb később, mint soha.', 'Лучше поздно, чем никогда.','Поздно плохо.','Никогда не поздно.','Время деньги.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Ne csinálj a bolhából elefántot.', 'Не делай из мухи слона.','Нет слона.','Муха и слон.','Большой слон.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Lényegében igazad van.', 'В сущности, ты прав.','Ты прав.','Конечно прав.','Да.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Alig várom.', 'Я с нетерпением жду.','Не жду.','Ждать долго.','Скоро.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Szeretnék panaszt tenni.', 'Я хочу подать жалобу.','Жалоба нет.','Плохо здесь.','Помогите.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Ha lett volna időm, segítettem volna.', 'Если бы у меня было время, я бы помог.','Было время, помог.','Время есть, помогу.','Нет времени.',0,1),
(3,2,2,'Hogyan mondod oroszul?','Minden a terv szerint halad.', 'Всё идёт по плану.','План хороший.','Нет плана.','Всё хорошо.',0,1);

--------------------------------------------------------
-- 3. PONTSZÁMOK / STATISZTIKA TÁBLA
--------------------------------------------------------
CREATE TABLE IF NOT EXISTS user_scores (
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    user_id INTEGER NOT NULL,
    language INTEGER NOT NULL,
    correct_answers INTEGER NOT NULL,
    total_questions INTEGER NOT NULL,
    total_points INTEGER NOT NULL,

    played_at DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);

--------------------------------------------------------
-- 3.a MINTA EREDMÉNY //VIKTORIA
--------------------------------------------------------
INSERT INTO user_scores (
    user_id, language, correct_answers, total_questions, total_points
) VALUES
(1, 1, 8, 10, 80);
