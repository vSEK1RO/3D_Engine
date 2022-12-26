# 3D_Engine
>Данный проект представляет собой трехмерный движок, включающий в себя методы управления камерой, объектами, их отрисовкой на экран. Базируется на библиотеке __SFML__
>This project is a three-dimensional engine that includes methods for controlling the camera, objects, and their drawing on the screen. Based on the __SFML__ library
На данный момент реализовано / Currently implemented

:white_check_mark: класс для работы с камерой / camera class

:black_square_button: класс для работы с объектами / class for working with objects

:black_square_button: класс для отрисовки ортогональной и перспективной проекций / class for rendering orthogonal and perspective projections 

# Документация / Documentation

### class Camera

Создайте объект класса Camera, после чего запустите в отдельном потоке конструктор класса cameraInit().
Далее используйте соответствующие методы геттеры и сеттеры для получения параметров камеры (координат, угла направления взгляда

Create an object of the Camera class, and then run the cameraInit() class constructor on a separate thread.
Next, use the appropriate getter and setter methods to get the camera parameters (coordinates, view angle).
     
     3D::Camera cam;
     sf::Thread camera(&sf3D::Camera::cameraInit, &cam);
     camera.launch();

### class Object

### class Projection