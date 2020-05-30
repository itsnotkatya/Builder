#include <iostream>
using namespace std;

enum Genre {
    Comedy,
    Thriller,
    Horror,
    Drama,
    Documentary,
    Fantasy
};

enum FilmStudio {
    WarnerBros,
    UniversalPictures,
    ColumbiaPictures,
    TwentyCenturyFox,
    ParamountPictures
};

enum Director {
    Spielberg,
    Scorsese,
    Hitchcock,
    Kubrick,
    Tarkovsky,
    Tarantino,
    Nolan
};

string getDenre (Genre genre) {
    switch (genre) {
        case Comedy : {
            return "Comedy";
        }
        case Thriller : {
            return "Thriller";
        }
        case Horror : {
            return "Horror";
        }
        case Drama : {
            return "Dramar";
        }
        case Documentary : {
            return "Documentary";
        }
        case Fantasy : {
            return "Fantasy";
        }
    }
}

string getFilmStudio (FilmStudio filmStudio) {
    switch(filmStudio) {
        case WarnerBros : {
            return "WarnerBros";
            }
        case UniversalPictures : {
            return "UniversalPictures";
        }
        case ColumbiaPictures : {
            return  "ColumbiaPictures";
        }
        case TwentyCenturyFox : {
            return "TwentyCenturyFox";
        }
        case ParamountPictures : {
            return "ParamountPictures";
        }
    }
}

string getDirector (Director director) {
    switch (director) {
        case Spielberg : {
            return "Spielberg";
        }
        case Scorsese : {
            return "Scorsese";
        }
        case Hitchcock : {
            return "Hitchcock";
        }
        case Kubrick : {
            return "Kubrick";
        }
        case Tarkovsky : {
            return "Tarkovsky";
        }
        case Tarantino : {
            return "Tarantino";
        }
        case Nolan : {
            return "Nolan";
        }
    }
}

class CinemaFactory {
private:
    FilmStudio filmStudio;
    Director director;
    Genre genre;
    string Writer;
    string Name;
    unsigned int YearOfIssue;
    unsigned int Collections;
public:

    CinemaFactory(FilmStudio filmStudio, Director director, Genre genre, string Writer,
            string Name, unsigned int YearOfIssue, unsigned int Collections) {
        this -> filmStudio = filmStudio;
        this -> director = director;
        this -> genre = genre;
        this -> Writer = Writer;
        this -> Name = Name;
        this -> YearOfIssue = YearOfIssue;
        this -> Collections = Collections;
    }

    virtual void Print() {
        cout << getFilmStudio(filmStudio) << endl;
        cout << getDenre(genre) << endl;
        cout << getDirector(director) << endl;
        cout << Writer << endl;
        cout << Name << endl;
        cout << YearOfIssue << endl;
        cout << Collections << endl;
    }
};

class CinemaBuilder {
private:
    FilmStudio filmStudio;
    Director director;
    Genre genre;
    string Writer;
    string Name;
    unsigned int YearOfIssue;
    unsigned int Collections;
public:

    virtual void setFilmStudio(FilmStudio filmStudio) {
        CinemaBuilder :: filmStudio = filmStudio;
    }

    virtual void setDirector(Director director) {
        CinemaBuilder :: director = director;
    }

    virtual void setGenre(Genre genre) {
        CinemaBuilder :: genre = genre;
    }

    virtual void setWriter(string Writer) {
        CinemaBuilder :: Writer = Writer;
    }

    virtual void setName(string Name) {
        CinemaBuilder :: Name = Name;
    }

    virtual void setYeafOfIssue(unsigned int YearOfIssue) {
        CinemaBuilder ::  YearOfIssue =  YearOfIssue;
    }

    virtual void setCollections(unsigned int Collections) {
        CinemaBuilder ::  Collections =  Collections;
    }

    CinemaFactory *build() {
        return new CinemaFactory(filmStudio, director, genre, Writer, Name, YearOfIssue, Collections);
    }

};

int main() {
    CinemaBuilder builder;

    builder.setFilmStudio(ParamountPictures);
    builder.setDirector(Nolan);
    builder.setGenre(Thriller);
    builder.setWriter("Nolan");
    builder.setName("Inception");
    builder.setYeafOfIssue(2010);
    builder.setCollections(296000000);

    CinemaFactory * cinemaFactory = builder.build();
    cinemaFactory -> Print();
    return 0;
}