#ifndef INDEX_HTML_H
#define INDEX_HTML_H

#include <pgmspace.h>

// High-quality, responsive portfolio webpage stored in Flash (PROGMEM)
const char portfolio_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en" data-theme="white">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Manav Jibhau Ahire | Portfolio</title>
    <style>
        /* Modern Minimalist Design System & Custom Themes */
        :root {
            --transition-speed: 0.3s;
            --font-primary: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
            --font-mono: SFMono-Regular, Consolas, "Liberation Mono", Menlo, monospace;
        }

        /* Minimalist White Theme */
        [data-theme="white"] {
            --bg-color: #fdfdfd;
            --bg-card: #ffffff;
            --text-primary: #1a1a1a;
            --text-secondary: #666666;
            --accent-color: #222222;
            --border-color: #eaeaea;
            --badge-bg: #f3f3f3;
            --badge-text: #333333;
            --shadow: 0 4px 20px rgba(0, 0, 0, 0.03);
            --header-border: #f0f0f0;
        }

        /* Rose Quartz Theme */
        [data-theme="rose"] {
            --bg-color: #faf5f5;
            --bg-card: #ffffff;
            --text-primary: #3d2f2f;
            --text-secondary: #8c7373;
            --accent-color: #c08081;
            --border-color: #ebdcdc;
            --badge-bg: #f5eae9;
            --badge-text: #8c5b5c;
            --shadow: 0 4px 20px rgba(192, 128, 129, 0.05);
            --header-border: #f2e4e4;
        }

        /* Sage & Olive Green Theme */
        [data-theme="olive"] {
            --bg-color: #f4f6f3;
            --bg-card: #ffffff;
            --text-primary: #2d362a;
            --text-secondary: #606d5c;
            --accent-color: #556b2f;
            --border-color: #e2e7df;
            --badge-bg: #ebf0e9;
            --badge-text: #415222;
            --shadow: 0 4px 20px rgba(85, 107, 47, 0.05);
            --header-border: #e6ece1;
        }

        /* CSS Reset & General Styles */
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            background-color: var(--bg-color);
            color: var(--text-primary);
            font-family: var(--font-primary);
            line-height: 1.6;
            padding: 40px 20px;
            transition: background-color var(--transition-speed), color var(--transition-speed);
        }

        .container {
            max-width: 760px;
            margin: 0 auto;
        }

        /* Theme Switcher Widget */
        .theme-switcher-container {
            display: flex;
            justify-content: flex-end;
            margin-bottom: 30px;
        }

        .theme-switcher {
            display: flex;
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            padding: 4px;
            border-radius: 30px;
            box-shadow: var(--shadow);
        }

        .theme-btn {
            background: transparent;
            border: none;
            cursor: pointer;
            padding: 6px 14px;
            font-size: 13px;
            font-family: var(--font-primary);
            font-weight: 500;
            color: var(--text-secondary);
            border-radius: 20px;
            transition: all var(--transition-speed);
        }

        .theme-btn:hover {
            color: var(--text-primary);
        }

        .theme-btn.active {
            background-color: var(--accent-color);
            color: #ffffff !important;
        }

        /* Typography & Header styling */
        header {
            margin-bottom: 40px;
            padding-bottom: 30px;
            border-bottom: 1px solid var(--header-border);
        }

        .header-content {
            display: flex;
            align-items: center;
            gap: 20px;
        }

        .monogram {
            font-family: var(--font-mono);
            font-weight: 700;
            font-size: 24px;
            background-color: var(--accent-color);
            color: #ffffff;
            width: 60px;
            height: 60px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-shrink: 0;
            box-shadow: var(--shadow);
            transition: background-color var(--transition-speed);
        }

        .title-area h1 {
            font-size: 28px;
            font-weight: 700;
            letter-spacing: -0.5px;
            margin-bottom: 4px;
        }

        .title-area p.location {
            font-size: 14px;
            color: var(--text-secondary);
            font-weight: 500;
        }

        .contact-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
            gap: 12px;
            margin-top: 20px;
        }

        .contact-item {
            display: flex;
            align-items: center;
            gap: 8px;
            text-decoration: none;
            color: var(--text-secondary);
            font-size: 13px;
            transition: color var(--transition-speed);
        }

        .contact-item:hover {
            color: var(--accent-color);
        }

        .contact-item svg {
            width: 16px;
            height: 16px;
            fill: currentColor;
        }

        /* Section Styling */
        section {
            margin-bottom: 40px;
        }

        section h2 {
            font-size: 16px;
            text-transform: uppercase;
            letter-spacing: 1.5px;
            color: var(--text-secondary);
            margin-bottom: 20px;
            font-weight: 600;
            position: relative;
        }

        section h2::after {
            content: '';
            position: absolute;
            bottom: -6px;
            left: 0;
            width: 30px;
            height: 2px;
            background-color: var(--accent-color);
            transition: background-color var(--transition-speed);
        }

        .profile-text {
            color: var(--text-primary);
            font-size: 15px;
            line-height: 1.7;
        }

        /* Timeline / Experience Elements */
        .timeline {
            display: flex;
            flex-direction: column;
            gap: 25px;
            position: relative;
            padding-left: 15px;
            border-left: 1px solid var(--border-color);
        }

        .timeline-item {
            position: relative;
        }

        .timeline-item::before {
            content: '';
            position: absolute;
            left: -20px;
            top: 6px;
            width: 9px;
            height: 9px;
            background-color: var(--bg-color);
            border: 2px solid var(--accent-color);
            border-radius: 50%;
            transition: border-color var(--transition-speed), background-color var(--transition-speed);
        }

        .timeline-header {
            display: flex;
            justify-content: space-between;
            align-items: baseline;
            margin-bottom: 8px;
            flex-wrap: wrap;
            gap: 5px;
        }

        .job-title {
            font-size: 16px;
            font-weight: 600;
        }

        .company {
            color: var(--text-secondary);
            font-weight: 400;
            font-size: 14px;
        }

        .date-badge {
            font-family: var(--font-mono);
            font-size: 12px;
            color: var(--accent-color);
            font-weight: 500;
        }

        .timeline-details {
            list-style: none;
            padding-left: 0;
        }

        .timeline-details li {
            font-size: 14px;
            color: var(--text-secondary);
            position: relative;
            padding-left: 15px;
            margin-bottom: 6px;
        }

        .timeline-details li::before {
            content: "•";
            color: var(--accent-color);
            position: absolute;
            left: 0;
            font-weight: bold;
        }

        /* Projects Layout */
        .project-card {
            background-color: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 8px;
            padding: 24px;
            box-shadow: var(--shadow);
            transition: all var(--transition-speed);
        }

        .project-card:hover {
            transform: translateY(-2px);
            border-color: var(--accent-color);
        }

        .project-title {
            font-size: 18px;
            font-weight: 700;
            margin-bottom: 6px;
        }

        .project-description {
            font-size: 14px;
            color: var(--text-secondary);
            margin-bottom: 16px;
        }

        .project-bullets {
            list-style: none;
            margin-bottom: 16px;
        }

        .project-bullets li {
            font-size: 13.5px;
            color: var(--text-secondary);
            position: relative;
            padding-left: 15px;
            margin-bottom: 6px;
        }

        .project-bullets li::before {
            content: "→";
            color: var(--accent-color);
            position: absolute;
            left: 0;
        }

        .tech-stack-inline {
            display: flex;
            gap: 8px;
            flex-wrap: wrap;
        }

        /* Skills Layout */
        .skills-container {
            display: flex;
            flex-direction: column;
            gap: 16px;
        }

        .skill-group {
            display: flex;
            align-items: center;
            border-bottom: 1px dashed var(--border-color);
            padding-bottom: 12px;
        }

        .skill-group:last-child {
            border-bottom: none;
            padding-bottom: 0;
        }

        .skill-label {
            width: 140px;
            font-weight: 600;
            font-size: 14px;
            color: var(--text-primary);
            flex-shrink: 0;
        }

        .skill-badges {
            display: flex;
            flex-wrap: wrap;
            gap: 8px;
        }

        .badge {
            background-color: var(--badge-bg);
            color: var(--badge-text);
            padding: 4px 10px;
            border-radius: 4px;
            font-size: 12px;
            font-weight: 500;
            font-family: var(--font-mono);
            transition: background-color var(--transition-speed), color var(--transition-speed);
        }

        /* Grids for Education and Soft skills */
        .edu-grid {
            display: flex;
            flex-direction: column;
            gap: 15px;
        }

        .edu-card {
            display: flex;
            justify-content: space-between;
            align-items: flex-start;
            padding: 16px;
            background-color: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 6px;
            box-shadow: var(--shadow);
            flex-wrap: wrap;
            gap: 10px;
        }

        .edu-info h3 {
            font-size: 15px;
            font-weight: 600;
            margin-bottom: 2px;
        }

        .edu-info p {
            font-size: 13px;
            color: var(--text-secondary);
        }

        .edu-score {
            font-family: var(--font-mono);
            font-size: 13px;
            background-color: var(--badge-bg);
            color: var(--badge-text);
            padding: 3px 8px;
            border-radius: 4px;
            font-weight: 600;
        }

        .grid-2col {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
        }

        .simple-card {
            background-color: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 6px;
            padding: 20px;
            box-shadow: var(--shadow);
        }

        .bullet-list {
            list-style: none;
        }

        .bullet-list li {
            font-size: 13.5px;
            color: var(--text-secondary);
            position: relative;
            padding-left: 18px;
            margin-bottom: 8px;
        }

        .bullet-list li::before {
            content: "✓";
            color: var(--accent-color);
            position: absolute;
            left: 0;
            font-weight: bold;
        }

        /* Footer styling */
        footer {
            margin-top: 50px;
            text-align: center;
            border-top: 1px solid var(--header-border);
            padding-top: 20px;
            font-size: 12px;
            color: var(--text-secondary);
        }

        @media (max-width: 480px) {
            body {
                padding: 20px 15px;
            }
            .header-content {
                flex-direction: column;
                align-items: flex-start;
                gap: 12px;
            }
            .timeline-header {
                flex-direction: column;
                align-items: flex-start;
            }
            .skill-group {
                flex-direction: column;
                align-items: flex-start;
                gap: 8px;
            }
            .skill-label {
                width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <!-- Floating Theme Selector -->
        <div class="theme-switcher-container">
            <div class="theme-switcher">
                <button class="theme-btn active" onclick="setTheme('white')">White</button>
                <button class="theme-btn" onclick="setTheme('rose')">Rose</button>
                <button class="theme-btn" onclick="setTheme('olive')">Olive</button>
            </div>
        </div>

        <header>
            <div class="header-content">
                <div class="monogram">MA</div>
                <div class="title-area">
                    <h1>Manav Jibhau Ahire</h1>
                    <p class="location">Nashik, Maharashtra, India</p>
                </div>
            </div>
            <div class="contact-grid">
                <span class="contact-item">
                    <svg viewBox="0 0 24 24"><path d="M20 4H4c-1.1 0-1.99.9-1.99 2L2 18c0 1.1.9 2 2 2h16c1.1 0 2-.9 2-2V6c0-1.1-.9-2-2-2zm0 4l-8 5-8-5V6l8 5 8-5v2z"/></svg>
                    manavahire60@gmail.com
                </span>
                <span class="contact-item">
                    <svg viewBox="0 0 24 24"><path d="M6.62 10.79c1.44 2.83 3.76 5.14 6.59 6.59l2.2-2.2c.27-.27.67-.36 1.02-.24 1.12.37 2.33.57 3.57.57.55 0 1 .45 1 1V20c0 .55-.45 1-1 1-9.39 0-17-7.61-17-17 0-.55.45-1 1-1h3.5c.55 0 1 .45 1 1 0 1.25.2 2.45.57 3.57.11.35.03.74-.25 1.02l-2.2 2.2z"/></svg>
                    +91 9637450994
                </span>
                <a href="https://linkedin.com" target="_blank" class="contact-item">
                    <svg viewBox="0 0 24 24"><path d="M19 3a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h14m-.5 15.5v-5.3a3.26 3.26 0 0 0-3.26-3.26c-.85 0-1.84.52-2.32 1.3v-1.11h-2.79v8.37h2.79v-4.93c0-.77.62-1.4 1.39-1.4a1.4 1.4 0 0 1 1.4 1.4v4.93h2.79M6.88 8.56a1.68 1.68 0 0 0 1.68-1.68c0-.93-.75-1.69-1.68-1.69a1.69 1.69 0 0 0-1.69 1.69c0 .93.76 1.68 1.69 1.68m1.39 9.94v-8.37H5.5v8.37h2.77z"/></svg>
                    LinkedIn
                </a>
                <a href="https://github.com" target="_blank" class="contact-item">
                    <svg viewBox="0 0 24 24"><path d="M12 2A10 10 0 0 0 2 12c0 4.42 2.87 8.17 6.84 9.5.5.08.66-.23.66-.5v-1.69c-2.77.6-3.36-1.34-3.36-1.34-.46-1.16-1.11-1.47-1.11-1.47-.9-.62.07-.6.07-.6 1 .07 1.53 1.03 1.53 1.03.9 1.52 2.34 1.07 2.91.83.09-.65.35-1.09.63-1.34-2.22-.25-4.55-1.11-4.55-4.92 0-1.11.38-2 1.03-2.71-.1-.25-.45-1.29.1-2.64 0 0 .84-.27 2.75 1.02.79-.22 1.65-.33 2.5-.33.85 0 1.71.11 2.5.33 1.91-1.29 2.75-1.02 2.75-1.02.55 1.35.2 2.39.1 2.64.65.71 1.03 1.6 1.03 2.71 0 3.82-2.34 4.66-4.57 4.91.36.31.69.92.69 1.85V21c0 .27.16.59.67.5C19.14 20.16 22 16.42 22 12A10 10 0 0 0 12 2z"/></svg>
                    GitHub
                </a>
            </div>
        </header>

        <!-- Profile Summary -->
        <section>
            <h2>Profile Summary</h2>
            <p class="profile-text">
                Third-year Computer Engineering student with frontend development experience and a solid technical foundation in web technologies, IoT, programming, and hardware. Passionate about building user-centric applications and continuous learning.
            </p>
        </section>

        <!-- Experience -->
        <section>
            <h2>Experience</h2>
            <div class="timeline">
                <div class="timeline-item">
                    <div class="timeline-header">
                        <div>
                            <span class="job-title">Frontend Development Intern</span>
                            <span class="company">at Innoknowvex</span>
                        </div>
                        <span class="date-badge">Remote</span>
                    </div>
                    <ul class="timeline-details">
                        <li>Developed an interactive web portfolio with contact form functionality and local storage integration.</li>
                        <li>Implemented responsive design principles using HTML, CSS, and JavaScript for seamless user experience.</li>
                        <li>Received comprehensive training on modern frontend development practices and workflow optimization.</li>
                    </ul>
                </div>
                <div class="timeline-item">
                    <div class="timeline-header">
                        <div>
                            <span class="job-title">Frontend Development Intern</span>
                            <span class="company">at GWING Software Technologies</span>
                        </div>
                        <span class="date-badge">Remote</span>
                    </div>
                    <ul class="timeline-details">
                        <li>Created responsive web components including navigation bars, footers, and image slideshow galleries.</li>
                        <li>Enhanced UI/UX through custom animations and modern design patterns.</li>
                    </ul>
                </div>
            </div>
        </section>

        <!-- Projects -->
        <section>
            <h2>Featured Project</h2>
            <div class="project-card">
                <div class="project-title">UCHIHADEX — Personal Productivity Booster App</div>
                <p class="project-description">
                    A comprehensive productivity and wellness application designed to help users structure their daily routines.
                </p>
                <ul class="project-bullets">
                    <li>Built productivity modules for mental health tracker, nutrition log, fitness regimens, study techniques, and time management.</li>
                    <li>Integrated interactive tools including a persistent calendar, Pomodoro timer, and to-do list with multiple custom theme options.</li>
                </ul>
                <div class="tech-stack-inline">
                    <span class="badge">HTML</span>
                    <span class="badge">CSS</span>
                    <span class="badge">JavaScript</span>
                </div>
            </div>
        </section>

        <!-- Skills -->
        <section>
            <h2>Technical Skills</h2>
            <div class="skills-container">
                <div class="skill-group">
                    <span class="skill-label">Languages</span>
                    <div class="skill-badges">
                        <span class="badge">Python</span>
                        <span class="badge">JavaScript</span>
                        <span class="badge">HTML</span>
                        <span class="badge">CSS</span>
                        <span class="badge">SQL</span>
                    </div>
                </div>
                <div class="skill-group">
                    <span class="skill-label">Tools & IDEs</span>
                    <div class="skill-badges">
                        <span class="badge">VS Code</span>
                        <span class="badge">PyCharm</span>
                        <span class="badge">IntelliJ IDEA</span>
                        <span class="badge">Sublime Text</span>
                        <span class="badge">Jupyter Lab</span>
                        <span class="badge">Git/GitHub</span>
                    </div>
                </div>
                <div class="skill-group">
                    <span class="skill-label">Libraries</span>
                    <div class="skill-badges">
                        <span class="badge">NumPy</span>
                        <span class="badge">Pandas (Learning)</span>
                    </div>
                </div>
                <div class="skill-group">
                    <span class="skill-label">Hardware & IoT</span>
                    <div class="skill-badges">
                        <span class="badge">Arduino</span>
                        <span class="badge">IoT Sensors</span>
                        <span class="badge">Electronics Logic</span>
                    </div>
                </div>
            </div>
        </section>

        <!-- Education & Soft Skills side by side -->
        <div class="grid-2col">
            <section style="margin-bottom: 0;">
                <h2>Education</h2>
                <div class="edu-grid">
                    <div class="edu-card">
                        <div class="edu-info">
                            <h3>B.E. in Computer Engineering</h3>
                            <p>L. G. N. Sapkal College of Engg.</p>
                            <p class="company">2023 - 2027</p>
                        </div>
                        <span class="edu-score">CGPA: 8.36</span>
                    </div>
                    <div class="edu-card">
                        <div class="edu-info">
                            <h3>HSC (12th Grade)</h3>
                            <p>K. D. Bhalerao Jr College, Malegaon</p>
                            <p class="company">Passing Year: 2023</p>
                        </div>
                        <span class="edu-score">80.20%</span>
                    </div>
                </div>
            </section>

            <section style="margin-bottom: 0;">
                <h2>Leadership & Activities</h2>
                <div class="simple-card">
                    <ul class="bullet-list">
                        <li><strong>Technical Lead</strong> at Genesis Coding Club, L. G. N. Sapkal College of Engineering.</li>
                        <li>Hosted live, hands-on IoT sessions on <strong>Arduino programming</strong> for peers.</li>
                        <li>Anchored multiple flagship college programs and tech festivals.</li>
                        <li><strong>Soft Skills:</strong> Public Speaking, Leadership, Time Management, Touch Typing (80 WPM).</li>
                    </ul>
                </div>
            </section>
        </div>

        <footer>
            <p>Manav Ahire &copy; 2026. Ayane Smartwatch Captive Node.</p>
        </footer>
    </div>

    <script>
        function setTheme(themeName) {
            document.documentElement.setAttribute('data-theme', themeName);
            const buttons = document.querySelectorAll('.theme-btn');
            buttons.forEach(btn => {
                if(btn.innerText.toLowerCase() === themeName) {
                    btn.classList.add('active');
                } else {
                    btn.classList.remove('active');
                }
            });
        }
    </script>
</body>
</html>
)rawliteral";

#endif
