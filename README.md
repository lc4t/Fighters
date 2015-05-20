# Fighters
The final of 2015CCPP:Plane Fighters

###Demand

- 完成SFML配置,显示"SFML works"
- 显示一架静止的飞机于屏幕底部
- 背景音乐
- 左右键,控制飞机
- 限制左右边界
- 空格键开炮,显示运动的炮弹
- 炮弹飞出边界处理
- 随机产生敌机,并向下运动
- 敌机飞出边界处理
- 碰撞处理(敌机与炮弹碰撞)
- 显示敌机爆炸过程
- 爆炸声音
- 计分及显示
- 被敌机击中处理(炸毁、3条命)
- 过关控制(过关需要计分、游戏速度控制)]

###Achieve
- install sfml
`yaourt -S aur/sfml-git`

- example code test
```c++
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
        window.draw(shape);
        window.display();
    }

    return 0;
}```

and change the liker settings
I use eclipse,so add the libraries at Plane ->Properties->C/C++ Build -> Settings ->Tool Settings -> GCC C Linker -> Labraries
`-L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system`

Then,test it.
Works!

- main.cpp 主程序
- config.h 存放常量,配置文件
- Stage
- backgroundImage
- Musics
- Object:
- 	Hero

