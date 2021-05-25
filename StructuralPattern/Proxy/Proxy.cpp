#include<iostream>
#include<memory>
#include<vector>

class Thumbnail
{
public:
    virtual void showTitle() = 0;
    virtual void showPreview() = 0;
};

class RealThumbnail : public Thumbnail
{
public:
    RealThumbnail() = default;

    RealThumbnail(std::string _title, std::string _movieUrl) : title(_title), movieUrl(_movieUrl)
    {
        std::cout << movieUrl << " 로부터 " << title << "의 영상 데이터 다운" << std::endl;
    }

    void showTitle() override
    {
        std::cout << "제목 : " << title << std::endl;
    }

    void showPreview() override
    {
        std::cout << title << "의 프리뷰 재생" << std::endl;
    }

private:
    std::string title;
    std::string movieUrl;
};

class ProxyThumbnail : public Thumbnail
{
public:
    ~ProxyThumbnail() = default;

    ProxyThumbnail(std::string _title, std::string _movieUrl) : title(_title), movieUrl(_movieUrl)
    {
        realThumbnail = nullptr;
    }

    void showTitle() override
    {
        std::cout << "제목 : " << title << std::endl;
    }

    // 프록시 능력을 벗어나는일
    // RealThumbnail 객체를 통해 실행한다.
    void showPreview() override
    {
        if (realThumbnail == nullptr)
        {
            realThumbnail = std::make_unique<RealThumbnail>(title, movieUrl);
        }
        realThumbnail->showPreview();
    }

private:
    std::string title;
    std::string movieUrl;
    std::unique_ptr<RealThumbnail> realThumbnail;
};

int main()
{
    std::vector<Thumbnail*> thumbnails;

    thumbnails.push_back(new ProxyThumbnail("Git 강좌", "/git.mp4"));
    thumbnails.push_back(new ProxyThumbnail("Rest API란?", "/rest-api.mp4"));
    thumbnails.push_back(new ProxyThumbnail("도커 사용법", "/docker.mp4"));
    thumbnails.push_back(new ProxyThumbnail("객체지향 프로그래밍", "/oop.mp4"));
    thumbnails.push_back(new ProxyThumbnail("블록체인의 원리", "/ blockchain.mp4"));

    for (auto thumbnail : thumbnails)
    {
        thumbnail->showTitle();
    }
    // 제목 : Git 강좌
    // 제목 : Rest API란?
    // 제목 : 도커 사용법
    // 제목 : 객체지향 프로그래밍
    // 제목 : 블록체인의 원리
    std::cout << std::endl << std::endl;

    thumbnails.at(2)->showPreview();
    thumbnails.at(2)->showPreview();
    thumbnails.at(4)->showPreview();
    thumbnails.at(1)->showPreview();
    // /docker.mp4로부터 도커 사용법의 영상 데이터 다운
    // 도커 사용법의 프리뷰 재생
    // 도커 사용법의 프리뷰 재생 (이미 생성해서 데이터는 다시 안받아옴)
    // /blockchain.mp4로부터 블록체인의 원리의 영상 데이터 다운
    // 블록체인의 원리의 프리뷰 재생
    // /rest-api.mp4로부터 Rest API란?의 영상 데이터 다운
    // Rest API란?의 프리뷰 재생
    return 0;
}