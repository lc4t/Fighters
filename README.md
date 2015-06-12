# Fighters
The final of 2015CCPP:Plane Fighters

###Demand

- 完成SFML配置,显示"SFML works"			 0
- 显示一架静止的飞机于屏幕底部			    5
- 背景音乐								  1
- 左右键,控制飞机						    10
- 限制左右边界 							 1
- 空格键开炮,显示运动的炮弹  				  5
- 炮弹飞出边界处理						    2
- 随机产生敌机,并向下运动					  10
- 敌机飞出边界处理   						2
- 碰撞处理(敌机与炮弹碰撞)					  10
- 显示敌机爆炸过程							10
- 爆炸声音								   2
- 计分及显示								  5
- 被敌机击中处理(炸毁、3条命)				  10
- 过关控制(过关需要计分、游戏速度控制)]		   20

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


//遇到两个飞机同时    在第一个飞机消失的时候第二个被炸
// 炸了第一个 又出来一个 第二个突然消失
// 飞机死的时候带走了它发的子弹 需要分离