#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Text title;
    sf::Text mostComplaint;
    sf::Text mostComplaintString;
    sf::Text mostComplaintWith;
    sf::Text mostComplaintCall;
    sf::Text mostComplaintCalls;
    sf::Text leastComplaint;
    sf::Text leastComplaintString;
    sf::Text leastComplaintWith;
    sf::Text leastComplaintCall;
    sf::Text leastComplaintCalls;
    sf::Text runtime;
    sf::Text runtimeVal;
    sf::Font font;
    // select the font
    if (!font.loadFromFile("resources/OpenSans-Regular.ttf")) {
        std::cout << "error" << std::endl;
        // error...
    }
    else {
        title.setFont(font);
        mostComplaint.setFont(font);
        mostComplaintString.setFont(font);
        mostComplaintWith.setFont(font);
        mostComplaintCall.setFont(font);
        mostComplaintCalls.setFont(font);
        leastComplaint.setFont(font);
        leastComplaintString.setFont(font);
        leastComplaintWith.setFont(font);
        leastComplaintCall.setFont(font);
        leastComplaintCalls.setFont(font);
        runtime.setFont(font);
        runtimeVal.setFont(font);
    }

    // set the string to display
    title.setString("KAIR Project");
    mostComplaint.setString("The most common complaint is: ");
    mostComplaintString.setString(ordered[0].second);
    mostComplaintWith.setString("With ");
    mostComplaintCall.setString(to_string(ordered[0].first));
    mostComplaintCalls.setString("calls");
    leastComplaint.setString("The least common complaint is: ");
    leastComplaintString.setString(ordered[size - 1].second);
    leastComplaintWith.setString("With ");
    leastComplaintCall.setString(to_string(ordered[size - 1].first));
    leastComplaintCalls.setString("calls");
    runtime.setString("Runtime: ");
    runtimeVal.setString(to_string(duration.count()));


    title.setScale(2.f, 2.f);
    mostComplaint.setScale(2.f, 2.f);
    mostComplaintString.setScale(2.f, 2.f);
    mostComplaintWith.setScale(2.f, 2.f);
    mostComplaintCall.setScale(2.f, 2.f);
    mostComplaintCalls.setScale(2.f, 2.f);
    leastComplaint.setScale(2.f, 2.f);
    leastComplaintString.setScale(2.f, 2.f);
    leastComplaintWith.setScale(2.f, 2.f);
    leastComplaintCall.setScale(2.f, 2.f);
    leastComplaintCalls.setScale(2.f, 2.f);
    runtime.setScale(2.f, 2.f);
    runtimeVal.setScale(2.f, 2.f);

    // set the character size
    title.setCharacterSize(24); // in pixels, not points!
    mostComplaint.setCharacterSize(24);
    mostComplaintString.setCharacterSize(24);
    mostComplaintWith.setCharacterSize(24);
    mostComplaintCall.setCharacterSize(24);
    mostComplaintCalls.setCharacterSize(24);
    leastComplaint.setCharacterSize(24);
    leastComplaintString.setCharacterSize(24);
    leastComplaintWith.setCharacterSize(24);
    leastComplaintCall.setCharacterSize(24);
    leastComplaintCalls.setCharacterSize(24);
    runtime.setCharacterSize(24);
    runtimeVal.setCharacterSize(24);

    // set the color
    title.setFillColor(sf::Color::Red);
    mostComplaint.setFillColor(sf::Color::Red);
    mostComplaintString.setFillColor(sf::Color::Blue);
    mostComplaintWith.setFillColor(sf::Color::Red);
    mostComplaintCall.setFillColor(sf::Color::Blue);
    mostComplaintCalls.setFillColor(sf::Color::Red);
    leastComplaint.setFillColor(sf::Color::Red);
    leastComplaintString.setFillColor(sf::Color::Blue);
    leastComplaintWith.setFillColor(sf::Color::Red);
    leastComplaintCall.setFillColor(sf::Color::Blue);
    leastComplaintCalls.setFillColor(sf::Color::Red);
    runtime.setFillColor(sf::Color::Red);
    runtimeVal.setFillColor(sf::Color::Blue);

    title.setPosition(50, 50);
    mostComplaint.setPosition(50, 100);
    mostComplaintString.setPosition(50, 150);
    mostComplaintWith.setPosition(50, 200);
    mostComplaintCall.setPosition(50, 250);
    mostComplaintCalls.setPosition(50, 300);
    leastComplaint.setPosition(50, 350);
    leastComplaintString.setPosition(50, 400);
    leastComplaintWith.setPosition(50, 450);
    leastComplaintCall.setPosition(50, 500);
    leastComplaintCalls.setPosition(50, 550);
    runtime.setPosition(50, 600);
    runtimeVal.setPosition(50, 650);

    // set the text style
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::RenderWindow window(sf::VideoMode(800, 800), "INTSWYM: Karens, am I Right? (KAIR) Project");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(title);
        window.draw(mostComplaint);
        window.draw(mostComplaintString);
        window.draw(mostComplaintWith);
        window.draw(mostComplaintCall);
        window.draw(mostComplaintCalls);
        window.draw(leastComplaint);
        window.draw(leastComplaintString);
        window.draw(leastComplaintWith);
        window.draw(leastComplaintCall);
        window.draw(leastComplaintCalls);
        window.draw(runtime);
        window.draw(runtimeVal);
        //window.draw(shape);
        window.display();
    }

    return 0;
}