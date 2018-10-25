#include "MeleeCommand.h"
#include "Animation.h"

//Animation m_a ;
/*MeleeCommand::MeleeCommand(Animation* a) {
	m_a = a;
}*/

void MeleeCommand::Melee(Animation* a) {
	printf("Attack");
	a->attack();
}