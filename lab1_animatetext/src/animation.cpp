#include <animation.h>
#include <iostream>




animatedText::animatedText(unsigned int duration, const std::string& text){
    m_duration = duration;
    m_text = std::move(text);
    m_interval = (m_text.length() * 1000000) / m_duration;
}

unsigned int animatedText::getInterval() const {
    return m_interval;
}

std::string animatedText::getText() const {
    return m_text;
}