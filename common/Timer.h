#pragma once
#include "common.h"

#include <vector>
#include <chrono>
#include <stdexcept>

namespace Common {

	typedef std::chrono::high_resolution_clock HiResClock;
	typedef std::chrono::microseconds microseconds;

	class COMMONDLL Timer
	{
	public:

		Timer()
			: head(nullptr, "Timer Root")
			, current(&this->head)
		{};

		~Timer() {};

	private:
		void addTask(std::string name) {
			this->current = this->current->addChild(name);
		}

		void stopTask(HiResClock::duration time) {
			this->current = this->current->close(time);
		}

	public:
		class COMMONDLL Task
		{
		protected:
			Timer& parent;
			HiResClock::time_point start;
		public:
			Task(Timer& parent, const std::string& name)
				: parent(parent)
				, start(HiResClock::now())
			{
				this->parent.addTask(name);
			}

			~Task() {
				this->parent.stopTask(HiResClock::now() - this->start);
			};
		};

	private:
		class Node {
		public:
			Node(Node* parent, std::string name)
				: parent(parent)
				, name(name)
				, time(0)
			{};

			Node* addChild(std::string name) {
				children.emplace_back(this, name);
				return &this->children.back();
			}

			Node* close(HiResClock::duration time) {
				this->time = time;
				return this->parent;
			}

		private:
			std::string name;
			HiResClock::duration time;

			Node* parent;
			std::vector<Node> children;
		};

		Node head;
		Node* current;
	};

};