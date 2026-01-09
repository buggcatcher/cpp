#include <iostream>
#include <string> // usa questo al posto di [] 

class Biology {
    public:
    std::string name;
    Biology(const std::string& n) : name(n) {}
    virtual ~Biology() {}
    bool dna;
    Biology() : name("Biology"), dna(true) { }
};
        class Bacteria : public Biology {
        public:
            Bacteria() { name = "Bacteria"; }
        };
                class EscherichiaColi : public Bacteria {
                public:
                    EscherichiaColi() { name = "Escherichia coli"; }
                };
                class LactobacillusAcidophilus : public Bacteria {
                public:
                    LactobacillusAcidophilus() { name = "Lactobacillus acidophilus"; }
                };
        class Eukaryotes : public Biology {
        public:
            double height;
        protected:          // age non è accessibile dall'esterno della classe
            int age;       // accessibile solo da Eukaryotes e classi derivate
        public:
        Eukaryotes() : Biology(), height(0.0), age(0) { name = "Eukaryotes"; }
        void showPrivateString() { privateString(); }
        void setAge(int a) { age = a; }
        int getAge() const { return age; }
        private:
            void privateString() {    // a differenza di protected, non è accessibile dalle classi derivate
                std::cout << "archea è inclusa in eucarioti causa endosimbiosi mitocondriale" << std::endl;
            }
        }; 
                class Animalia : public Eukaryotes {
                public:
                    enum Sex { Male, Female, Unknown };
                    Sex sex;
                    Animalia() : sex(Unknown) { name = "Animalia"; }
                protected:
                    std::string lifeStage(int sogliaBambino, int sogliaVecchio) const {
                        if (age < sogliaBambino) return "young";
                        else if (age < sogliaVecchio) return "adult";
                        else return "old";
                    }
                };
                            class Mammal : public Animalia {
                            public:
                                Mammal() { name = "Mammal"; }
                                virtual std::string verso() const { return ""; } // polimorfismo 
                            };        //  metodo che può essere ridefinito nelle classi derivate
                                    class Dog : public Mammal {
                                    public:
                                        Dog() { name = "Dog"; }
                                        std::string verso() const { return "bark"; }
                                        std::string getLifeStage() const {
                                            return lifeStage(2, 8);
                                        }
                                    };
                                    class Cat : public Mammal {
                                    public:
                                        Cat() { name = "Cat"; }
                                        std::string verso() const { return "meow"; }
                                    };
                                    class Cow : public Mammal {
                                    public:
                                        Cow() { name = "Cow"; }
                                        std::string verso() const { return "moo"; }
                                    };
                                    class Human : public Mammal {
                                    public:
                                        std::string face;
                                        Human() {
                                            name = "Human";
                                        }
                                        void walk(int speed) {                          // overloading
                                            std::cout << "walking at " << speed << " km/h"; 
                                        }       // stesso nome definito con tipi diversi: int -> float
                                        void walk(float speed) {
                                            std::cout << "walking at " << speed * 0.621371 << " m/ph";
                                        }
                                        std::string verso() const { return "speak"; }
                                        std::string getLifeStage() const {
                                            return lifeStage(18, 65);
                                        }
                                    };
                                            class Marko : public Human {
                                            public:
                                                Marko() {
                                                    name = "Marko";
                                                    face = "smiling";
                                                    age = 28;
                                                    height = 1.75;
                                                    dna = false;
                                                    powerLevel = 9312;
                                                }
                                            public:
                                                void walk(double speed) {
                                                    std::cout << "Marko is walking at " << speed << " km/h";
                                                }
                                            public:
                                                void introduce() {
                                                    std::cout <<"Greetings my friend, my secret is ";
                                                    revealSecret();
                                                }
                                            private:                                    // metodo privato
                                                void revealSecret() { std::cout << "kiwi" << std::endl; }
                                            private:
                                                int powerLevel;         // variabile privata inacessibile
                                            };                         // per mancanza dmetodo rivelatore
                            class Insects : public Animalia {
                            public:
                                Insects() { name = "Insects"; }
                            };
                            class Birds : public Animalia {
                            public:
                                Birds() { name = "Birds"; }
                            };
                class Plantae : public Eukaryotes {
                public:
                    Plantae() { name = "Plantae"; }
                };
                class Fungi : public Eukaryotes {
                public:
                    Fungi() { name = "Fungi"; }
                };


int main()
{
    Plantae albero;
    albero.name = "Pino";
    albero.height = 33.0;
    albero.dna = true;

    Dog fido;
    fido.name = "Fido";
    fido.height = 0.3;
    fido.sex = Animalia::Sex::Male;
    fido.dna = true;
    //fido.age = 1; // non è accessibile dal main
    fido.setAge(1); // metodo pubblico

    Human franco;
    franco.name = "Franco";
    franco.face = "serious";
    franco.height = 2.0;
    franco.sex = Animalia::Sex::Male;
    franco.dna = false;

    Human andrea;
    andrea.name = "Andrea";
    andrea.face = "happy";
    andrea.height = 1.70;
    andrea.sex = Animalia::Sex::Unknown;
    andrea.dna = false;

    if (albero.dna == fido.dna) {
        std::cout << franco.name << " " << franco.verso() << "s: bravo cucciolo." << "\n";
        std::cout << fido.name << " " << fido.verso() << "s: woof woof!" << "\n";
    }
    int velocità_int = 5;
    float velocità_float = velocità_int;
    std::cout << velocità_float;
    std::cout << "\n";
    std::cout << std::fixed << velocità_float;
    std::cout << std::endl << "std::endl per andare a capo in cpp style" << std::endl; 
    franco.walk(velocità_int);
    std::cout << std::endl;
    franco.walk(velocità_float);
    std::cout << std::endl;

    Marko marko;
    marko.getAge();   // accesso a metodo protected tramite istanza di Marko
    std::cout << "Marko is " << marko.getAge() << " years old" << std::endl;
    marko.setAge(0);
    std::cout << "Marko's age was set to " << marko.getAge() << std::endl;
    marko.showPrivateString();
    std::cout << marko.name << "'s " << marko.face << std::endl;
    std::cout << marko.name << " " << marko.verso() << "s to " << franco.name << std::endl;
    marko.introduce();
    //marko.revealSecret();
    std::cout << "Franco's face looks " <<  franco.face << std::endl;
    //std::cout << "Fido is a " << fido.age << " dog" << std::endl;
    std::cout << "Fido is a " << fido.getLifeStage() << " dog" << std::endl;
    marko.dna = true;
    if (fido.dna == marko.dna) {
        std::cout << "Fido pissed on Marko's leg" << std::endl;
    }
    marko.face = "angry";
    std::cout << marko.name<< "'s " << marko.face << std::endl;

    return 0;
}
/* Oggi è stato il mio primo giorno a scrivere in C++. Ho sperimentato il concetto di ereditarietà e ho capito che 
categorizzare i tratti biologici è intrinsecamente inaccurato. Sembra più plausibile che tutto esista su uno spettro,
anche se troviamo la categorizzazione utile e sufficientemente descrittiva per scopi pratici.*/

/* 2° giorno ho giocato con il polimorfismo e l'overloading ho continuato con variabili e metodi protected/private.*/