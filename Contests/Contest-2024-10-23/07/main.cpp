#include <iostream>
#include <string>
#include <vector>

class Canvas{
    std::vector<std::string> buffer;

    void expand(int width, int height) {
        if (this->height() < height)
            buffer.resize(height, std::string(this->width(), ' '));
    
        if (this->width() < width) 
            for (auto& line : buffer)
                line.resize(width, ' ');
    }
public:
    void draw(const Canvas& other, int posX=0, int posY=0){
         expand(posX + other.width(), posY + other.height());
         for (int i=0; i<other.height(); i++)
            for (int j=0; j<other.width(); j++)
                buffer[posY + i][posX + j] = other.buffer[i][j];
    }
    
    void draw(const std::string& str, int posX=0, int posY=0){
        expand(posX + str.size(), posY+1);
        for (int i=0; i<str.size(); i++) buffer[posY][posX + i] = str[i];
    }
    
    int width() const {
        return (buffer.size() == 0)? 0 : buffer[0].size();
    }
    
    int height() const {
        return buffer.size();
    }
    
    void print(){
        for (auto& line : buffer) std::cout << line << std::endl;
    }
};

class Component{
public:
    virtual Canvas render() = 0;
    virtual std::string click(int x, int y) = 0;
    virtual void add(Component* c) = 0;
    virtual ~Component() = 0;
};

Component::~Component(){
};

class Leaf: public Component{
public:
    void add(Component* c) override{
        throw "Is not Composite";
    }
    
    ~Leaf() override = default;
};

class Composite: public Component{
protected:
    std::vector<Component*> components;
public:
    void add(Component* c) override{
        components.push_back(c);
    }

    ~Composite() override{
        for(auto i : components) delete i;
    }
};

class Button: public Leaf{
    std::string text;
public:
    Button(const std::string& text):text(text){
    }
    
    Canvas render() override{
        Canvas c;

        c.draw("+" + std::string(text.size() + 2, '-') + "+");
        c.draw("| " + text + " |", 0, 1);
        c.draw("+" + std::string(text.size() + 2, '-') + "+", 0, 2);
        
        return c;
    }
    
    std::string click(int x, int y) override{
        return "Button(" + text + ")";
    }
};

class HLayout: public Composite{
public:
    Canvas render() override{
        Canvas c;

        for(auto i : components){
            Canvas t = i->render();
            c.draw(t, c.width()==0 ? 0 : c.width() + 1, 0);
        }
        
        return c;
    }
    
    std::string click(int x, int y) override{
        int curX = 0;
        int curY = 0;
        
        for(auto i : components){
            Canvas t = i->render();
            curX += t.width();
            curY = t.height();
            
            if (curX > x){
                if (curY > y) {
                    return i->click(x - (curX - t.width()), y);
                }else return "Empty";
            }
            
            curX += 1;
            if (curX > x) return "Empty";
        }
        return "Empty";
    }
};

class Panel: public Component{
    int padding = 1;
    int border = 1;
    
    Component* layout;
public:
    Panel(Component* layout = nullptr): layout(layout){
    }
    
    void set_layout(Component* layout){
        delete this->layout;
        this->layout = layout;
    }
    
    ~Panel(){
        delete layout;
    }
    
    void add(Component* c) override{
        if (layout == nullptr) throw "Empty layout";
        layout->add(c);
    }
    
    Canvas render() override{
        Canvas content;
        if (layout != nullptr) content = layout->render();
        
        Canvas panel;
        panel.draw("+" + std::string(content.width() + 2*padding, '-') + "+");
        panel.draw(content, border + padding, border);
        for(int i=border; i<border + content.height(); i++){
            panel.draw("|", 0, i);
            panel.draw("|", 2*border + 2*padding + content.width()-1, i);
        }
        panel.draw("+" + std::string(content.width() + 2*padding, '-') + "+", 0, border + content.height());
        
        return panel;
    }
    
    std::string click(int x, int y) override{
        if (x - border - padding >= 0 and y - border >= 0)
            return layout->click(x - border - padding, y - border);
        return "Empty";
    }
};

// Ваш код здесь
#pragma once

int main(){
    auto main_panel = Panel(new VLayout());
  
    auto header = new Label("QUIZ");
    auto main_content = new HLayout();
    auto footer = new HLayout();
    
    main_panel.add(header);
    main_panel.add(main_content);
    main_panel.add(footer);
    
    footer->add(new Button("PREV"));
    footer->add(new Button("NEXT"));
    
    auto quiz = new VLayout();
    auto side_bar = new VLayout();
    
    main_content->add(quiz);
    main_content->add(new Panel(side_bar));
    
    quiz->add(new Label("What goes up when the rain comes down?"));
    quiz->add(new CheckBox("Umbrella", true));
    quiz->add(new CheckBox("Cat", false));
    quiz->add(new CheckBox("Elephant", false));
    
    auto side_bar_row1 = new HLayout();
    auto side_bar_row2 = new HLayout();
    auto side_bar_row3 = new HLayout();
    auto side_bar_row4 = new HLayout();
    side_bar->add(side_bar_row1);
    side_bar->add(side_bar_row2);
    side_bar->add(side_bar_row3);
    side_bar->add(side_bar_row4);
    
    side_bar_row1->add(new Button("1"));
    side_bar_row1->add(new Button("2"));
    side_bar_row2->add(new Button("3"));
    side_bar_row2->add(new Button("4"));
    side_bar_row3->add(new Button("5"));
    side_bar_row3->add(new Button("6"));
    side_bar_row4->add(new Button("7"));

    Canvas c = main_panel.render();
    c.print();
    
    int n, x, y;
    std::cin >> n;
    while(n--){
        std::cin >> x >> y;
        std::cout << main_panel.click(x, y) << std::endl;
    }
}
