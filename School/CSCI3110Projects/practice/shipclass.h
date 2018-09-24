#ifndef SHIPCLASS_H
#define SHIPCLASS_H

namespace ships{
	class Ship{
		public:
			//default constructor
			Ship(){
				ammunition = 0;
				health = 100;
			}
		
			//returns the ships current amount of health
			int getHealth() const{ return heatlh; }
				
			//returns amount of current ammunition
			int getAmmunitionCount() const{ return ammunition; }

			//moves the ship across the map
			void setPosition();

			//fires the ships LHS cannons
			void fireLHSCannons();

			//fires the ships RHS cannons
			void fireRHSCannons();

			//returns number of ships in the fleet
			void getFleet() const{ return fleet; }

		private:
			int ammunition;
			int health;
			
			//number of ships in the fleet
			static int fleet
			//used to reduce the ships health after taking a hit
			void setHealth();
	}		
}
#endif
