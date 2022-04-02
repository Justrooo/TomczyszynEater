#include "ExitButton.h"
ExitButton::ExitButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos) : Button(w, t, pos)
{
}
void ExitButton::onClick(Shop& shop, Game& game, dataToSave& dataTS)
{
    ofstream binFile("Assets/Data/data.dat", ios::in | ios::binary);
    dataTS.money = game.balance();
    dataTS.current_skin = shop.getPointer();
    dataTS.current_bgskin = shop.getBgPointer();

    bool* sk;
    sk = shop.isBought();
    char sk_char[8];
    for (int i = 0; i < 8; i++)
    {
        if (sk[i] == true) sk_char[i] = 'o';
        else if (sk[i] == false) sk_char[i] = 'n';
    }
    for (int i = 0; i < 8; i++)
    {
        dataTS.skins[i] = sk_char[i];
    }
    bool* bsk;
    char bsk_char[4];
    bsk = shop.isBgBought();
    for (int i = 0; i < 4; i++)
    {
        if (bsk[i] == true) bsk_char[i] = 'o';
        else if (bsk[i] == false) bsk_char[i] = 'n';
    }
    for (int i = 0; i < 4; i++)
    {
        dataTS.bg_skins[i] = bsk_char[i];
    }
    // Write
    binFile.write((char*)&dataTS, sizeof(dataTS));

    delete sk; delete bsk;
    // Close
    binFile.close();
	window->close();
}