# So_Long
This is a 2D game I designed as part of the So_Long Project at 42 Abu Dhabi. The main objective of the game is to escape the map after collecting all the coins whilst evading patrolling enemies. The player also has the ability to build the elements of the map to their liking as long as long as they respect the rules specified. 

There are two versions of the game:
1. Mandatory
2. Bonus

The mandatory part does not contain any patrolling enemies. It can just be used as practice mode to get familiar with the mechanics and the general layout of the map.
The bonus part on the other hand contains patrolling enemies and is quite challening. The best strategy would be to figure out the patterns in which the enemies move to workaround their high speed.


To start the games, do the following:

For mandatory (type the following in the terminal):
1. make all
2. ./so_long ./maps/(enter the name of the map you'd like to play (you can even create your own map))

For bonus (type the following in the temrinal):
1. make bonus
2. ./so_long_bonus ./bonus/maps/(enter the name of the map you'd like to play (you can even create your own map))


Map Elements:
1. C stands for Coin
2. P stands for Player Position
3. E stands for exit portal
4. 1 stands for wall
5. 0 stands for movable space
6. N stands for enemies (only works with so_long_bonus)

Map Rules:
1. Map must be rectangular (squares accpeted)
2. Map must be surrounded by walls
3. Player must have a valid path (able to collect all coins and head to an exit)
4. Map must only have one player, one exit, and at least coin
5. Enemies shall not be placed within 3 spaces of a wall or a coin (design your map accordingly)