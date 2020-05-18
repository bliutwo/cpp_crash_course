struct Movable{
    Movable(int id) : id{ id } { }
    Movable(Movable&& m) {
        id = m.id;
        m.id = -1;
    }
    int id;
};
