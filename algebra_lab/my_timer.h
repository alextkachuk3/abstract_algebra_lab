#pragma once
#include <chrono>

/**
*	\brief Namespacefor class Timer
*/
namespace mtimer
{
	using Time = std::chrono::steady_clock::time_point;/**< Short name of time_point in library chrono*/
	using Duration = std::chrono::duration<float>;/**< Short name of duration<float> in library chrono*/
	/**
	*	\brief Timer for measurement time of functions work
	* 
	*	Before the function starting place create timer and delete it after function has done.
	*/
	class Timer
	{
	private:
		Time start_point;/**< Start time point*/
		float& time;/**< Reference to result time */
	public:
		/**
		*	\brief Starts timer
		* 
		*	\param time - reference to result
		*/
		Timer(float& time);
		/**
		*	\brief Stops timer and edit time value to time of life of timer
		*/
		~Timer();
	};
}