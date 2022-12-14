/**
* \file dcm_core_net_tsqueue_radar.h
* \brief Header for dcm_core_net_tsqueue_radar.cpp
* @author Stefan Ackermann <stefan.ackermann@tu-darmstadt.de>
* @date 14.07.2021
* @version 1
* @copyright MIT License
* @bug No known bugs.
* Copyright (c) Stefan Ackermann (2021) <stefan.ackermann@tu-darmstadt.de>
**********************************************************************/

#ifndef DCM_CORE_NET_TSQUEUE_RADAR_H
#define DCM_CORE_NET_TSQUEUE_RADAR_H

/*************************************************************************
@class tsmsgqueue
@brief Class for threadsafe message queue
@author Stefan Ackermann, <stefan.ackermann@tu-darmstadt.de>
@date 14.07.2021
*************************************************************************/
class tsmsgqueue {

protected:

/*************************************************************************
@brief Mutex for deque message queue
@date 14.07.2021
*************************************************************************/
    std::mutex mx_deqMsgQueue;

/*************************************************************************
@brief Deque message queue
@date 14.07.2021
*************************************************************************/
    std::deque<std::string> deqMsgQueue;

/*************************************************************************
@brief Conditonal variable for deque message queue
@date 14.07.2021
*************************************************************************/
    std::condition_variable cv_deqMsgQueue;

/*************************************************************************
@brief Mutex for conditonal variable for deque message queue
@date 14.07.2021
*************************************************************************/
    std::mutex mx_cv_deqMsgQueue;

public:

/*************************************************************************
@brief This is the constructor of tsmsgqueue
@date 14.07.2021
*************************************************************************/
    tsmsgqueue() = default;

/*************************************************************************
@brief This is one constructor of tsmsgqueue
@date 14.07.2021
*************************************************************************/
    tsmsgqueue(const tsmsgqueue&) = delete;

/*************************************************************************
@brief This is the virtual destructor of tsmsgqueue
@date 14.07.2021
*************************************************************************/
    virtual ~tsmsgqueue();

/*************************************************************************
@brief This function returns string at front of deque message queue
@date 14.07.2021
*************************************************************************/
    const std::string& front();

/*************************************************************************
@brief This function returns string at back of deque message queue
@date 14.07.2021
*************************************************************************/
    const std::string& back();

/*************************************************************************
@brief This function removes and returns string at front of deque message queue
@return String at front of message queue
@date 14.07.2021
*************************************************************************/
    std::string pop_front();

/*************************************************************************
@brief This function removes and returns string at back of deque message queue
@return String at back of message queue
@date 14.07.2021
*************************************************************************/
    std::string pop_back();

/*************************************************************************
@brief This function adds a string to back of deque message queue
@param item String to be added at back of message queue
@date 14.07.2021
*************************************************************************/
    void push_back(const std::string& item);

/*************************************************************************
@brief This function adds a string to front of deque message queue
@param item String to be added at front of message queue
@date 14.07.2021
*************************************************************************/
    void push_front(const std::string& item);

/*************************************************************************
@brief Returns true if deque message queue has no strings
@returns Returns true if deque message queue has no strings
@date 14.07.2021
*************************************************************************/
    bool empty();

/*************************************************************************
@brief Returns number of strings in deque message queue
@returns eturns number of strings in deque message queue
@date 14.07.2021
*************************************************************************/
    size_t count();

/*************************************************************************
@brief Clears deque message queue
@date 14.07.2021
*************************************************************************/
    void clear();

/*************************************************************************
@brief Primes a wait for next element to be added to the deque or waittime milliseconds
@param[in] waittime Maximum waittime in milliseconds
@date 14.07.2021
*************************************************************************/
    void wait(uint16_t waittime);

/*************************************************************************
@brief Primes a wait for next element to be added to the deque
@date 02.08.2021
*************************************************************************/
    void wait();

};

#endif //DCM_CORE_NET_TSQUEUE_RADAR_H