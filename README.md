Russian
.......
English


Испольщованне 
1. **Библиотека graphics.h**: Основные функции, используемые в коде, включают initwindow(), setbkcolor(), settextstyle(), outtextxy(), rectangle(), bar(), setfillstyle(), floodfill(), cleardevice(), swapbuffers(), ismouseclick(), mousex(), mousey(), getch(), и closegraph().
 
2. **Стандартная библиотека C++**:
   - `iostream`: Для ввода-вывода (в данном коде не используется непосредственно, но подключена).
   - `stdlib.h`: Для вызова функции `rand()` и `srand()`, используемых для генерации случайных чисел.
   - `time.h`: Для функции `time()`, используемой для инициализации генератора случайных чисел.

3. **Функции и управление потоком**:
   - Функции `moveCarLeft()`, `moveCarRight()`, `drawCar()`, `drawBackground()`, `main()`: Определяют основные элементы игры, такие как управление движением автомобиля, рисование автомобиля и фона, а также основной игровой цикл.
   - Циклы `while(1)` и `for`: Используются для непрерывного выполнения игрового цикла и рисования полос на дороге.
   - Условные операторы `if`: Для обработки событий, таких как клики мышью и столкновения.

4. **Обработка событий мыши**:
   - `ismouseclick()`, `mousex()`, `mousey()`: Для обработки кликов мыши и определения координат клика.
   
5. **Графические функции для рисования и взаимодействия**:
   - `setcolor()`, `rectangle()`, `bar()`, `floodfill()`, `setfillstyle()`, `cleardevice()`, `swapbuffers()`: Для рисования и анимации элементов игры.

6. **Игровая логика**:
   - Основной цикл игры управляет движением фона (дороги), движением автомобиля игрока и противника, проверкой столкновений, обновлением счета и завершением игры при столкновении.
.........................................................................................................................................................................................................................................................


I used the following technologies.

1. **graphics.h Library**: The main functions used in the code include `initwindow()`, `setbkcolor()`, `settextstyle()`, `outtextxy()`, `rectangle()`, `bar()`, `setfillstyle()`, `floodfill()`, `cleardevice()`, `swapbuffers()`, `ismouseclick()`, `mousex()`, `mousey()`, `getch()`, and `closegraph()`.

2. **Standard C++ Library**:
   - `iostream`: For input-output operations (not used directly in this code, but included).
   - `stdlib.h`: For calling the `rand()` and `srand()` functions, used for generating random numbers.
   - `time.h`: For the `time()` function, used to initialize the random number generator.

3. **Functions and Control Flow**:
   - Functions `moveCarLeft()`, `moveCarRight()`, `drawCar()`, `drawBackground()`, `main()`: Define the main game elements, such as car movement control, drawing the car and background, and the main game loop.
   - `while(1)` and `for` loops: Used for continuously running the game loop and drawing the road stripes.
   - Conditional statements `if`: For handling events like mouse clicks and collisions.

4. **Mouse Event Handling**:
   - `ismouseclick()`, `mousex()`, `mousey()`: For handling mouse clicks and determining the coordinates of the click.
   
5. **Graphic Functions for Drawing and Interaction**:
   - `setcolor()`, `rectangle()`, `bar()`, `floodfill()`, `setfillstyle()`, `cleardevice()`, `swapbuffers()`: For drawing and animating game elements.

6. **Game Logic**:
   - The main game loop manages the movement of the background (road), the player's car, and the opponent's car, checks for collisions, updates the score, and ends the game in case of a collision.

