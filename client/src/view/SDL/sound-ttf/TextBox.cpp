#include "TextBox.h"

TextBox::TextBox(char *text, SDL_Renderer* mainRenderer, SDL_Color color, int size) {

    this->font = loadfont("ttf/MetalSlug.TTF", size);
    this->color = color;
    this->mainRenderer =  mainRenderer;
    this->textRect.x = this->textRect.y = 0;
    changeText(text);

}

TextBox::TextBox(int number, SDL_Renderer* mainRenderer, SDL_Color color, int size) {
    this->font = loadfont("ttf/MetalSlug.TTF", size);
    this->color = color;
    this->mainRenderer =  mainRenderer;
    this->textRect.x = this->textRect.y = 0;
    changeText(number);
}

void TextBox::changeText(char* text){
    SDL_Surface *textSurface = TTF_RenderText_Solid(this->font,text, this->color);
    this->text = SDL_CreateTextureFromSurface(this->mainRenderer,textSurface);
    SDL_QueryTexture(this->text, NULL, NULL, &textRect.w, &textRect.h);
    SDL_FreeSurface(textSurface);
}

void TextBox::changeText(int number) {
    string s = to_string(number);
    char pchar[5];
    sprintf(pchar, "%.5s", s.c_str());
    changeText(pchar);
}

void TextBox::changeText(string text) {
    char pchar[20];
    sprintf(pchar, "%.20s", text.c_str());
    changeText(pchar);
}
void TextBox::renderize(int x, int y) {
    this->setPosition(x,y);
    SDL_RenderCopy(mainRenderer, text, NULL, &textRect);
}

void TextBox::setPosition(int x, int y){
    this->textRect.x = x;
    this->textRect.y = y;
}

void TextBox::renderize() {
    SDL_RenderCopy(mainRenderer, text, NULL, &textRect);
}
TTF_Font* TextBox::loadfont(char* file, int ptsize) {
    TTF_Font* tmpfont;
    tmpfont = TTF_OpenFont(file, ptsize);
    if (tmpfont == NULL) {
        printf("Unable to load font: %s %s \n", file, TTF_GetError());
        // Handle the error here.
    }
    return tmpfont;
}
TextBox::~TextBox() {
    SDL_DestroyTexture(text);
    text = NULL;
}