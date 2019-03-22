
template < typename container >
void speedTest(container & students, container & vargsiukai, bool strat1) {
    cout.flush();
    Timer t;
    readFromFile(students, vargsiukai, "kursiokai10.txt", strat1);
    cout << "Darbas su \"kursiokai10.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100.txt", strat1);
    cout << "Darbas su \"kursiokai100.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai1000.txt", strat1);
    cout << "Darbas su \"kursiokai1000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai10000.txt", strat1);
    cout << "Darbas su \"kursiokai10000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100000.txt", strat1);
    cout << "Darbas su \"kursiokai100000.txt\" užtruko: " << t.elapsed() << " s" << endl;
}

void containerTest() {
    cout << "Startegija 2" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<student> students;
    vector<student> vargsiukai;
    students.reserve(100000);
    vargsiukai.reserve(100000);
    speedTest(students, vargsiukai, false);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<student> studentsDeque;
    deque<student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, false);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

   cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
   t.reset();
   list<student> studentsList;
   list<student> vargsiukaiList;
   speedTest(studentsList, vargsiukaiList, false);
   cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;
}

// Pirmoji strategija
void containerTestBadStrat() {
    cout << "Startegija 1" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<student> students;
    vector<student> vargsiukai;
    students.reserve(100000);
    vargsiukai.reserve(100000);
    speedTest(students, vargsiukai, true);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
    t.reset();
    list<student> studentsList;
    list<student> vargsiukaiList;
    speedTest(studentsList, vargsiukaiList, true);
    cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<student> studentsDeque;
    deque<student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, true);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;
}