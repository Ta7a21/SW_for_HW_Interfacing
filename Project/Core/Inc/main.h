#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#define DEFINE_REG(PORT_ID, REG_ID) (*(unsigned int *)(PORT_ID + REG_ID))
#define REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

#endif /* INC_MAIN_H_ */
