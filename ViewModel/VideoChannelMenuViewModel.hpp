/*
 * VideoChannelMenuViewModel.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef VIDEOCHANNELMENUVIEWMODEL_H_
#define VIDEOCHANNELMENUVIEWMODEL_H_

#include "VideoChannel.h"

class VideoChannelMenuViewModel {
public:
	VideoChannel videoChannel;

	VideoChannelMenuViewModel(VideoChannel& videoChannel): videoChannel(videoChannel) {

	}

	uint8_t* getChannelName();

	virtual ~VideoChannelMenuViewModel();
};

#endif /* VIDEOCHANNELMENUVIEWMODEL_H_ */
