/*
 * MainNavigationController.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef MAINNAVIGATIONCONTROLLER_H_
#define MAINNAVIGATIONCONTROLLER_H_

#include "Stack.h"
#include "ViewController.h"

class MainNavigationController {
public:
	MainNavigationController();
	virtual ~MainNavigationController();

private:
	Stack<ViewController, 10> navigationStack;

};

#endif /* MAINNAVIGATIONCONTROLLER_H_ */
