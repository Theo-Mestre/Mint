#ifndef GAME_PCH_H
#define GAME_PCH_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <iterator>
#include <initializer_list>

#include <memory>
#include <functional>
#include <algorithm>

#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>

#include <type_traits>
#include <typeindex>
#include <typeinfo>

#include <cassert>

#include <cmath>
#include <ctime>

#include <random>
#include <limits>
#include <utility>

#include <optional>
#include <variant>
#include <any>

#include <locale>
#include <codecvt>
#include <regex>
#include <tuple>
#include <numeric>

#ifndef SPDLOG_HEADER_ONLY
#define SPDLOG_HEADER_ONLY
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/ansicolor_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/sinks/ostream_sink.h>
#endif

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Core/Logger.h"

#endif