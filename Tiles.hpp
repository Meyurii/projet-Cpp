#ifndef TILE_HPP
#define TILE_HPP

#include <vector>


class Tile {
    private:
        std::vector<std::vector<std::vector<int>>> listTile;
        std::vector<std::vector<std::vector<int>>> randomTile;
        std::vector<int> usedTiles;
    public:
        Tile();
        ~Tile();
        void SetTiles();
        void SetRandomTile();
        void display();
        void popFirstTile();
        std::vector<std::vector<std::vector<int>>> GetTiles();
        void SetTiles(const std::vector<std::vector<std::vector<int>>>& newTiles) {
        randomTile = newTiles;
    }
};

Tile::Tile(){
    this->SetTiles();
    this->SetRandomTile();
};

Tile::~Tile(){}

std::vector<std::vector<std::vector<int>>> Tile::GetTiles(){
    return randomTile;
};

void Tile::popFirstTile() {
    randomTile.erase(randomTile.begin());
}

void Tile::SetRandomTile() {
    for (int i = 0; i < 96; i++) {
        int randomIndex = rand() % listTile.size(); 
        randomTile.push_back(listTile[randomIndex]);
        listTile.erase(listTile.begin() + randomIndex);
    }
}






void Tile::SetTiles(){
    listTile = 
    {
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 2--,
        {{1,0,0,0,0},
        {1,0,0,0,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 3--,
        {{1,1,1,1,0},
        {0,0,0,1,0},
        {0,0,1,1,0},
        {0,0,0,0,0},
        {0,0,0,1,0}
        },
        // 4--,
        {{1,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 5--,
        {{1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 6--,
        {{1,0,0,0,0},
        {1,1,0,0,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 7--,
        {{1,0,0,0,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 8--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 9--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0}
        },
        // 10--,
        {{1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,0},
        {0,0,0,1,0},
        {0,0,0,1,0}
        },
        // 11--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 12--,
        {{1,1,1,0,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 13--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,0,0,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 14--,
        {{1,1,0,0,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 15--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 16--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 17--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 18--,
        {{1,0,1,0,0},
        {1,1,1,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 19--,
        {{1,0,0,0,0},
        {1,0,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 20--,
        {{1,0,0,0,0},
        {1,1,0,0,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 21--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {0,0,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 22--,
        {{1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 23--,
        {{1,1,0,0,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 24--,
        {{1,1,0,0,0},
        {0,1,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 25--,
        {{1,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0}
        },
        // 26--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 27--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 28--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 29--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 30--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        },
        // 31--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 32--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
        },
        // 33--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 34--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 35--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 36--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 37--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 38--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 39--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 40--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 41--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 42--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 43--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 44--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 45--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 46--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 47--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 48--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 49--,
        {{1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 50--,
        {{1,0,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 51--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 52--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 53--,
        {{0,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 54--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 55--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 56--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 57--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 58--,
        {{0,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 59--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 60--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        // 61--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 62--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 63--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 64--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //65--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //66--,
        {{1,1,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //67--,
        {{0,0,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //68--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //69--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //70--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //71--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //72--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //73--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //74--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //75--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //76--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //77--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //78--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //79--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //80--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //81--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //82--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //83--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}},
        //84--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //85--,
        {{1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //86--,
        {{1,0,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //87--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //88--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //89--,
        {{1,1,0,0,0},
        {0,1,1,0,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}}
        ,
        //90--,
        {{1,0,0,0,0},
        {1,1,1,1,0},
        {0,0,0,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //91--,
        {{1,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0}}
        ,
        //92--,
        {{1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //93--,
        {{1,1,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //94,
        {{1,0,0,0,0},
        {1,0,0,1,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        //95--,
        {{1,1,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,0},
        {0,0,0,0,0}}
        ,
        // 96,
        {{1,0,0,0,0},
        {1,1,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}},
    };
}




#endif // TILES_HPP
