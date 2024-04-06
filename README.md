# XEngine
[![Discord](https://img.shields.io/discord/635140721908908049?style=flat&logo=discord&logoColor=fff)](https://discord.gg/jw6YSwTFrU) [![Documentation Status](https://readthedocs.org/projects/xengine-docs/badge/?version=latest)](https://xengine-docs.readthedocs.io/ru/latest/?badge=latest)
       [![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)
 Понятный, кроссплатформенный и полностью настраиваемый движок для создания игр и программ.

## Возмодности создания игр
 На данный момент движок работает как програмный слой (имеет редактор с конфигурацией).
## Возмодности создания программ
 Ведётся работа над нативной UI библиотекой (xengine.ui).
## Пакетная система
 Весь функционал движка поставляется через пакеты. Автоматически включаются только отрисовщик тестового GUI, загрузчики контента и мат. база. Дополнительно пакеты можно загружать с [сайта пакетов](https://xanytka.ru/p/).

# Политика публикации
 Игры и программы можно свободно публиковать в любом интернет-магазине (XGLauncher, Steam, Epic Games Store и т.д.).
 При издании физических копий игры необходимо [сделать запрос к Xanytka](https://support.xanytka.ru/publisher/phys_copies).

# Сторонние библиотеки
* [GLM](https://github.com/g-truc/glm)
* [ImGUI](https://github.com/ocornut/imgui)
* [Assimp](https://github.com/assimp/assimp)
* [STB](https://github.com/nothings/stb)
* [JSON](https://github.com/nlohmann/json)

# Как скачать новейшую версию?
 Если вам необходимо уже готовое приложение, то качайте релизную версию в пункте [релизов](https://github.com/xanytka-devs/xengine/releases).
Иначе, для работы с самой новой, ещё не вышедшей версией, вам необходимо:
## Установка для Windows:
* Запустить команду `git clone --recursive https://github.com/xanytka-devs/xengine.git` 
* Скомпоновать проект через CMake версии `>=3.12` (или можно использовать скрипт "AutoCMake.cmd" для Windows)
* Построить движок через Visual Studio (или любой другой IDE для C++)
* Добавить в папку с построенной программой папку `res` из директории с склонированным проектом (при постройке в **Release**).
_Такие версии могут быть крайне нестабильны, а перенос проектов на такую базу_ **НЕ РЕКОМЕНДУЕТСЯ**. Бета-тест ожидается феврале-январе/весной 2024 года.
> Установка для Linux и MacOS ещё не продумана.