#include "JumpCommand.h"
#include "Animation.h"

//Animation m_a ;
/*MeleeCommand::MeleeCommand(Animation* a) {
	m_a = a;
}*/

void JumpCommand::Jump(Animation* a) {
	printf("Attack");
	a->jumping();
}