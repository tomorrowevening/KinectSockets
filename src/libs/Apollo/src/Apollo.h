//
//  Apollo.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once

// Apollo

#include "ApolloCore.h"

// Utils
#include "ApolloMath.h"
#include "ApolloStrings.h"
#include "ApolloTime.h"

// Enums
#include "ApolloColor.h"
#include "ApolloVec3.h"

// Events
#include "ApolloEvent.h"
#include "ApolloEventHandler.h"
#include "ApolloEventDispatcher.h"

// Display
#include "ApolloGL.h"
#include "ApolloDisplayObject.h"
#include "ApolloButton.h"
#include "ApolloToggle.h"
#include "ApolloInput.h"
#include "ApolloScene.h"
#include "ApolloStage.h"

// Animation
#include "ApolloInterpolation.h"
#include "ApolloSpringController.h"
#include "ApolloTweenController.h"

// External
#ifdef APOLLO_OPENFRAMEWORKS
#include "ApolloOFDispatcher.h"
#endif
