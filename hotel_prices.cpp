#include <iostream>
#include <vector>
using namespace std;

class HotelRoom {
public:
    int bedrooms;
    int bathrooms;

    HotelRoom(int bedrooms, int bathrooms) {
        this->bedrooms = bedrooms;
        this->bathrooms = bathrooms;
    }

    virtual int get_price() {
        return 50 * bedrooms + 100 * bathrooms;
    }

    virtual ~HotelRoom() {}
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms)
        : HotelRoom(bedrooms, bathrooms) {}

    int get_price() override {
        return HotelRoom::get_price() + 100; // +100 extra for apartment
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;

    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms, bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;

        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_price = 0;
    for (auto room : rooms) {
        total_price += room->get_price();
        delete room; // Free memory
    }

    cout << total_price << endl;
    return 0;
}
